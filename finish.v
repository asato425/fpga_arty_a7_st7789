/*************************************************************************************************/
/***** 240x240 ST7789 mini display project, Arduino sketch  Ver.2024-11-26a                  *****/
/***** Copyright (c) 2024 Suzuki Asato,  Science Tokyo                                          *****/
/***** Released under the MIT license https://opensource.org/licenses/mit                    *****/
/*************************************************************************************************/
`default_nettype none

`ifdef SYNTHESIS  
`define WAIT_CNT 100
`else
`define WAIT_CNT 10
`endif
  
/*********************************************************************************************/
module m_main(
    input  wire w_clk,          // main clock signal (100MHz)
    input  wire [3:0] w_button, //
    output wire [3:0] w_led,    //
    inout  wire st7789_SDA,     //
    output wire st7789_SCL,     //
    output wire st7789_DC,      //
    output wire st7789_RES      //
);
    reg [31:0] r_cnt = 0;
    always @(posedge w_clk) r_cnt <= r_cnt + 1;
    assign w_led = r_cnt[30:27];

    reg [15:0] wadr  = 0;
    reg [31:0] r_x = 0;
    reg [31:0] r_y = 0;
    
    reg bit0, bit1, bit2, bit3; // ボタンを保存するレジスタ

    reg [31:0] counter = 0;
    reg [31:0] limit = 5;
    reg [31:0] shuffle_counter = 0;
    reg[31:0] state [0:8][0:1]; 
    reg[31:0] swap [0:3]; 
    reg[31:0] swap2 [0:3]; 
    reg[31:0] cursor[0:1];
    reg[31:0] diff_x = 0;
    reg[31:0] diff_y = 0;
    reg[31:0] tmp_x = 0;
    reg[31:0] tmp_y = 0;
    reg[31:0] cursor_check_x = 0;
    reg[31:0] cursor_check_y = 0;
    reg[31:0] cursor_x = 0;
    reg[31:0] cursor_y = 0;
    integer i,j;
    integer random_value;
    reg [31:0] seed;
    reg [1:0] finish = 0;
    reg reset = 1;
    reg [2:0] init_state = S_INIT;
    
    localparam S_INIT   = 0, // 初期化ステート
               S_RANDOM  = 1; // ランダム値生成
               
    
    always @(posedge w_clk) counter <= (counter == 400000000) ? 0 : counter + 1;
    // 初期化処理
    always @(posedge w_clk) begin
    	if(reset == 1) begin
	    	if(init_state == S_INIT) begin
		    	cursor[0] <= 2;
		    	cursor[1] <= 2;
		    
		    	state[0][0] <= 2;
		    	state[0][1] <= 2;
		    	
		    	state[1][0] <= 0;
		    	state[1][1] <= 0;
		    	
		    	state[2][0] <= 1;
		    	state[2][1] <= 0;
		    	
		    	state[3][0] <= 2;
		    	state[3][1] <= 0;
		    	
		    	state[4][0] <= 0;
		    	state[4][1] <= 1;
		    	
		    	state[5][0] <= 1;
		    	state[5][1] <= 1;
		    	
		    	state[6][0] <= 2;
		    	state[6][1] <= 1;
		    	
		    	state[7][0] <= 0;
		    	state[7][1] <= 2;
		    	
		    	state[8][0] <= 1;
		    	state[8][1] <= 2;
		    	init_state <= S_RANDOM;
		    	seed = counter;
		    	shuffle_counter <= 0;
		end else if(init_state == S_RANDOM) begin
		
			shuffle_counter <= shuffle_counter + 1;
			if(shuffle_counter == 100) begin
				init_state <= S_INIT;
				reset <= 0;
			end
			
			random_value = $random(seed) % 8 + 1;
			diff_x = (state[0][0] > state[random_value][0]) ? state[0][0] - state[random_value][0] : 
									   state[random_value][0] - state[0][0];
	    		diff_y = (state[0][1] > state[random_value][1]) ? state[0][1] - state[random_value][1] : 
	    		                                                   state[random_value][1] - state[0][1];
	  
	    		if( diff_x + diff_y == 1) begin
	    			tmp_x = state[0][0];
			    	tmp_y = state[0][1];
			    	state[0][0] = state[random_value][0];
			    	state[0][1] = state[random_value][1];
			    	state[random_value][0] = tmp_x;
			    	state[random_value][1] = tmp_y;
			    	limit = limit + 1;
			    	
	    		end
		end
	end
    end


    always @(posedge w_clk) begin
        r_x <= (r_x==239) ? 0 : r_x + 1;
        r_y <= (r_y==239 && r_x==239) ? 0 : (r_x==239) ? r_y + 1 : r_y;
    end
    
    reg [15:0] r_st_wadr  = 0;
    reg        r_st_we    = 0;
    reg [15:0] r_st_wdata = 0;
   
    always @(posedge w_clk) r_st_wadr  <= {r_y[7:0], r_x[7:0]};
    always @(posedge w_clk) r_st_we    <= 1; 
    
    always @(posedge w_clk) begin
    	if((finish == 2) && (60 <= r_x && r_x <= 180 && (r_x == r_y || r_x + r_y == 240))) begin
        	r_st_wdata <= 16'he8c1;
        end else if ((finish == 1) &&  
        	    ( 3500 <= (r_x-120)*(r_x-120)+(r_y-120)*(r_y-120) && (r_x-120)*(r_x-120)+(r_y-120)*(r_y-120) <= 3700)) begin
        	r_st_wdata <= 16'he8c1;
        //cursor
        end else if((((r_x == (79 * cursor[0] + 2)) || (r_x == 79*cursor[0] + 3) || (r_x == 79*cursor[0] + 4) || 
    	     (r_x == 79*(cursor[0]+1)) || (r_x == 79*(cursor[0]+1)-1) || (r_x == 79*(cursor[0]+1)-2)) && 
    	    (79*cursor[1] + 2 <= r_y) && (r_y <= 79*(cursor[1]+1))) ||
    	    (((r_y == 79*cursor[1] + 2) || (r_y == 79*cursor[1] + 3) || (r_y == 79*cursor[1] + 4) || 
    	      (r_y == 79*(cursor[1]+1)) || (r_y == 79*(cursor[1]+1)-1) || (r_y == 79*(cursor[1]+1)-2)) && 
    	    (79*cursor[0] + 2 <= r_x) && (r_x <= 79*(cursor[0]+1)))) begin
    		r_st_wdata <= 16'h1277;
	//box
    	end else if(((r_x == 1) || (r_x == 80) || (r_x == 159) || (r_x == 238) || (r_y == 1) || (r_y == 80) || (r_y == 159) || (r_y == 238)) 
    		     && (r_x != 0) && (r_x != 239) && (r_y != 0) && (r_y != 239) ) begin
    		r_st_wdata <= 16'h0000;//black
    	//1	
    	end else if((r_x == 79*state[1][0] + 40) && (79*state[1][1]+20 <= r_y) && (r_y <= 79*state[1][1]+60)) begin
            r_st_wdata <= 16'h0000;//black
    	//2
    	end else if(((79*state[2][0]+20 <= r_x) && (r_x <= 79*state[2][0]+60) && ((r_y == 79*state[2][1] + 20) || (r_y == 79*state[2][1] + 40) || (r_y == 79*state[2][1] + 60))) || //横
                    (((r_x == 79*state[2][0] + 20) && (79*state[2][1]+40 <= r_y) && (r_y <= 79*state[2][1]+60)) || ((r_x == 79*state[2][0] + 60) && (79*state[2][1]+20 <= r_y) && (r_y <= 79*state[2][1]+40)))) begin//縦
            r_st_wdata <= 16'h0000;//black
    	//3
    	end else if(((79*state[3][0]+20 <= r_x) && (r_x <= 79*state[3][0]+60) && ((r_y == 79*state[3][1] + 20) || (r_y == 79*state[3][1] + 40) || (r_y == 79*state[3][1] + 60))) || //横
                    ((r_x == 79*state[3][0] + 60) && (79*state[3][1]+20 <= r_y) && (r_y <= 79*state[3][1]+60))) begin
            r_st_wdata <= 16'h0000;//black
    	//4
    	end else if(((79*state[4][1]+20 <= r_y) && (r_y <= 79*state[4][1]+60) && (r_x == 79*state[4][0] + 60)) ||
                    ((79*state[4][1]+20 <= r_y) && (r_y <= 79*state[4][1]+40) && (r_x == 79*state[4][0] + 20)) ||
                    ((79*state[4][0]+20 <= r_x) && (r_x <= 79*state[4][0]+60) && (r_y == 79*state[4][1] + 40))) begin
            r_st_wdata <= 16'h0000;//black
    	//5
    	end else if(((79*state[5][0]+20 <= r_x) && (r_x <= 79*state[5][0]+60) && ((r_y == 79*state[5][1] + 20) || 
    		     (r_y == 79*state[5][1] + 40) || (r_y == 79*state[5][1] + 60))) || //横
                    (((r_x == 79*state[5][0] + 20) && (79*state[5][1]+20 <= r_y) && (r_y <= 79*state[5][1]+40)) || 
                    ((r_x == 79*state[5][0] + 60) && (79*state[5][1]+40 <= r_y) && (r_y <= 79*state[5][1]+60)))) begin
            r_st_wdata <= 16'h0000;//black
    	//6
    	end else if(((79*state[6][0]+20 <= r_x) && (r_x <= 79*state[6][0]+60) && ((r_y == 79*state[6][1] + 20) || (r_y == 79*state[6][1] + 40) || (r_y == 79*state[6][1] + 60))) || //横
                    (((r_x == 79*state[6][0] + 20) && (79*state[6][1]+20 <= r_y) && (r_y <= 79*state[6][1]+60)) || ((r_x == 79*state[6][0] + 60) && (79*state[6][1]+40 <= r_y) && (r_y <= 79*state[6][1]+60)))) begin
            r_st_wdata <= 16'h0000;//black
    	//7
    	end else if(((79*state[7][1]+20 <= r_y) && (r_y <= 79*state[7][1]+60) && (r_x == 79*state[7][0] + 60)) ||
                    ((79*state[7][1]+20 <= r_y) && (r_y <= 79*state[7][1]+40) && (r_x == 79*state[7][0] + 20)) ||
                    ((79*state[7][0]+20 <= r_x) && (r_x <= 79*state[7][0]+60) && (r_y == 79*state[7][1] + 20))) begin
            r_st_wdata <= 16'h0000;//black
    	//8
    	end else if(((79*state[8][0]+20 <= r_x) && (r_x <= 79*state[8][0]+60) && ((r_y == 79*state[8][1] + 20) || (r_y == 79*state[8][1] + 40) || (r_y == 79*state[8][1] + 60))) || //横
                    (((r_x == 79*state[8][0] + 20) && (79*state[8][1]+20 <= r_y) && (r_y <= 79*state[8][1]+60)) || ((r_x == 79*state[8][0] + 60) && (79*state[8][1]+20 <= r_y) && (r_y <= 79*state[8][1]+60)))) begin
            r_st_wdata <= 16'h0000;//black
        //in box
        end else if((1 <= r_x) && (r_x <= 238) && (1 <= r_y) && (r_y <= 238) ) begin   
            r_st_wdata <= 16'he73e;   
        //out box   
    	end else begin
    		r_st_wdata <= 16'hffff;
        end
        
        
    end
    
    //operation
    always @(posedge w_clk) begin
    		
        bit0 <= w_button[0];
        bit1 <= w_button[1]; 
        bit2 <= w_button[2];
        bit3 <= w_button[3];
        cursor_check_x <= (state[0][0] > cursor[0]) ? state[0][0] - cursor[0] : cursor[0] - state[0][0];
        cursor_check_y <= (state[0][1] > cursor[1]) ? state[0][1] - cursor[1] : cursor[1] - state[0][1];
       
        if((bit0 == 1) && (cursor_check_x + cursor_check_y == 1) && (reset == 0) && (finish == 0))begin
            for(i = 1; i <= 8; i = i + 1) begin
                if((cursor[0] == state[i][0]) && (cursor[1] == state[i][1])) begin
                     tmp_x = state[0][0];
                     tmp_y = state[0][1];
                     state[0][0] = state[i][0];
                     state[0][1] = state[i][1];
                     state[i][0] = tmp_x;
                     state[i][1] = tmp_y;
                     if (limit > 0) begin
                     	limit = limit - 1;
                     	if(limit == 0) begin
                     		if((state[0][0] != 2)||(state[0][1] != 2)||(state[1][0] != 0)||(state[1][1] != 0)||(state[2][0] != 1)||
                     		   (state[2][1] != 0)||(state[3][0] != 2)||(state[3][1] != 0)||(state[4][0] != 0)||(state[4][1] != 1)||
                     		   (state[5][0] != 1)||(state[5][1] != 1)||(state[6][0] != 2)||(state[6][1] != 1)||(state[7][0] != 0)||
                     		   (state[7][1] != 2)||(state[8][0] != 1)||(state[8][1] != 2)) begin
					finish <= 2;
				end
                     		limit = 5;
                     	end
                     end

                end
            end
            if((state[0][0] == 2)&&(state[0][1] == 2)&&(state[1][0] == 0)&&(state[1][1] == 0)&&(state[2][0] == 1)&&(state[2][1] == 0)&&
               (state[3][0] == 2)&&(state[3][1] == 0)&&(state[4][0] == 0)&&(state[4][1] == 1)&&(state[5][0] == 1)&&(state[5][1] == 1)&&
               (state[6][0] == 2)&&(state[6][1] == 1)&&(state[7][0] == 0)&&(state[7][1] == 2)&&(state[8][0] == 1)&&(state[8][1] == 2)) begin
                finish <= 1;
            end
        end
        
        if ((bit1 == 1) && (finish == 0)) begin
            cursor[0] <= (cursor[0] + 1) % 3;
        end
        if((bit2 == 1) && (finish == 0))begin
            cursor[1] <= (cursor[1] + 1) % 3;
        end
        if(bit3 == 1) begin
            reset <= 1;
            finish <= 0;
        end
        
    end
 
    wire [15:0] r_rdata = 0;
    VMem vmem0 (w_clk, r_st_wadr, r_st_wdata, r_st_we, r_rdata);
    
    wire [1:0]  w_mode = w_button[0] + w_button[1] + w_button[2] + w_button[3];
    wire [15:0] w_raddr;
    //reg [15:0] r_rdata = 0;
    reg [15:0] r_raddr = 0;
    always @(posedge w_clk) r_raddr <= w_raddr;
    //always @(posedge w_clk) r_rdata <= vmem[r_raddr];
    m_st7789_disp disp0 (w_clk, st7789_SDA, st7789_SCL, st7789_DC, st7789_RES,
                         w_raddr, r_rdata, w_mode);
endmodule

module VMem (
    input  wire        w_clk,        // クロック信号
    input  wire [15:0] r_st_wadr,       // アドレス入力
    input  wire [15:0] r_st_wdata,      // 書き込みデータ
    input  wire        r_st_we,         // 書き込みイネーブル
    output reg  [15:0] rdata       // 読み出しデータ
);
	
    reg [15:0] r_adr_p = 0;
    reg [15:0] r_dat_p = 0;
    // メモリの定義（256x256, 16ビット）
    reg [15:0] vmem [0:65535];

    always @(posedge w_clk) if(r_st_we) begin
        if(vmem[r_st_wadr]!=r_st_wdata) begin
            r_adr_p <= r_st_wadr;
            r_dat_p <= r_st_wdata;
            $write("@D%0d_%0d\n", r_st_wadr ^ r_adr_p, r_st_wdata ^ r_dat_p);
            $fflush();
            vmem[r_st_wadr] <= r_st_wdata;
            rdata <= vmem[r_st_wadr];
        end
    end
endmodule

/*********************************************************************************************/
module m_st7789_disp(
    input  wire w_clk, // main clock signal (100MHz)
    inout  wire st7789_SDA,
    output wire st7789_SCL,
    output wire st7789_DC,
    output wire st7789_RES,
    output wire [15:0] w_raddr,
    input  wire [15:0] w_rdata,
    input  wire [1:0]  w_mode
);
    reg [31:0] r_cnt=1;
    always @(posedge w_clk) r_cnt <= (r_cnt==0) ? 0 : r_cnt + 1;
    reg r_RES = 1;
    always @(posedge w_clk) begin
        if      (r_cnt==10_000) r_RES <= 0;
        else if (r_cnt==20_000) r_RES <= 1;
    end
    assign st7789_RES = r_RES;    
       
    wire busy; 
    reg r_en = 0;
    reg init_done = 0;
    reg [4:0]  r_state  = 0;   
    reg [19:0] r_state2 = 0;   
 
    reg [8:0] r_dat = 0;

    reg [15:0] r_c = 16'hf800;
    reg [15:0] r_pagecnt = 0;
   
    always @(posedge w_clk) if(!init_done) begin
        r_en <= (r_cnt>30_000 && !busy && r_cnt[10:0]==0); 
    end else begin
        r_en <= (!busy);
    end
    
    always @(posedge w_clk) if(r_en && !init_done) r_state  <= r_state  + 1;
    
    always @(posedge w_clk) if(r_en &&  init_done) begin
        r_state2 <= (r_state2==115210) ? 0 : r_state2 + 1; // 11 + 240x240*2 = 11 + 115200 = 115211
        if(r_state2==115210) r_pagecnt <= r_pagecnt + 1;
    end

    reg [7:0] r_x = 0;
    reg [7:0] r_y = 0;
    always @(posedge w_clk) if(r_en &&  init_done && r_state2[0]==1) begin
       r_x <= (r_state2<=10 || r_x==239) ? 0 : r_x + 1;
       r_y <= (r_state2<=10) ? 0 : (r_x==239) ? r_y + 1 : r_y;
    end
    
    wire [7:0] w_nx = 239-r_x;
    wire [7:0] w_ny = 239-r_y; 
    //assign w_raddr = (w_mode==0) ? {r_y, r_x} :  // default
    //                 (w_mode==1) ? {r_x, w_ny} : // 90 degree rotation
    //                 (w_mode==2) ? {w_ny, w_nx} : {w_nx, r_y} ; //180 degree, 240 degree rotation
    assign w_raddr = {r_y, r_x};
    
    reg  [15:0] r_color = 0;
    always @(posedge w_clk) r_color <= w_rdata;  
 
    always @(posedge w_clk) begin
        case (r_state2) /////
            0:  r_dat<={1'b0, 8'h2A};     //
            1:  r_dat<={1'b1, 8'h00};     //
            2:  r_dat<={1'b1, 8'h00};     //
            3:  r_dat<={1'b1, 8'h00};     //
            4:  r_dat<={1'b1, 8'd239};    //
            5:  r_dat<={1'b0, 8'h2B};     //
            6:  r_dat<={1'b1, 8'h00};     //
            7:  r_dat<={1'b1, 8'h00};     //
            8:  r_dat<={1'b1, 8'h00};     //
            9:  r_dat<={1'b1, 8'd239};    //
            10: r_dat<={1'b0, 8'h2C};     //  
            default: r_dat <= (r_state2[0]) ? {1'b1, r_color[15:8]} :{ 1'b1, r_color[7:0]}; 
        endcase
    end
    
    reg [8:0] r_init = 0;
    always @(posedge w_clk) begin
        case (r_state) /////
            0:  r_init<={1'b0, 8'h01};  //
            1:  r_init<={1'b0, 8'h11};  //
            2:  r_init<={1'b0, 8'h3A};  //
            3:  r_init<={1'b1, 8'h55};  //
            4:  r_init<={1'b0, 8'h36};  //
            5:  r_init<={1'b1, 8'h00};  //
            6:  r_init<={1'b0, 8'h2A};  //
            7:  r_init<={1'b1, 8'h00};  //
            8:  r_init<={1'b1, 8'h00};  //
            9:  r_init<={1'b1, 8'h00};  //
            10: r_init<={1'b1, 8'd240}; //
            11: r_init<={1'b0, 8'h2B};  //
            12: r_init<={1'b1, 8'h00};  //
            13: r_init<={1'b1, 8'h00};  //
            14: r_init<={1'b1, 8'h00};  //
            15: r_init<={1'b1, 8'd240}; //
            16: r_init<={1'b0, 8'h21};  //
            17: r_init<={1'b0, 8'h13};  //
            18: r_init<={1'b0, 8'h29};  //
            19: init_done <= 1;
        endcase
    end

    wire [8:0] w_data = (init_done) ? r_dat : r_init;
    m_spi spi0 (w_clk, r_en, w_data, st7789_SDA, st7789_SCL, st7789_DC, busy);
endmodule

/****** SPI send module,  SPI_MODE_2, MSBFIRST                                           *****/
/*********************************************************************************************/
module m_spi(
    input  wire w_clk,       // 100KHz input clock !!
    input  wire en,          // enable
    input  wire [8:0] d_in,  //
    inout  wire SDA,         // 
    output wire SCL,         // 
    output wire DC,          // 
    output wire busy         // busy
);
    reg [5:0] r_state=0;  //
    reg [7:0] r_cnt=0;    //
    reg r_SCL = 1;        //
    reg r_SDA = 1;        //
    reg r_DC  = 0;        // Data/Control
    reg [7:0] r_data = 0; //

    always @(posedge w_clk) begin
        if(en && r_state==0) begin
            r_state <= 1;
            r_data  <= d_in[7:0];
            r_DC    <= d_in[8];
            r_SDA   <= 0;
            r_cnt   <= 0;
        end
        else begin
            r_cnt <= (r_state==0) ? 0 : r_cnt + 1;
            if(r_state!=0 && r_cnt==18) r_state <= 0;
            if(r_cnt>0 && r_cnt[0]==0) r_data <= {r_data[6:0], 1'b0};
        end
    end

    always @(posedge w_clk) if(r_state!=0 && (r_cnt>=1) && (r_cnt<=16)) r_SCL <= ~r_SCL;

    assign SDA = r_data[7];
    assign SCL = r_SCL;
    assign DC  = r_DC;
    assign busy = (r_state!=0 || en);
endmodule
/*********************************************************************************************/
