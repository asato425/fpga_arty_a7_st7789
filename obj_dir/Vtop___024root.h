// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ top__DOT__r_clk;
    CData/*7:0*/ top__DOT__main1__DOT__r_x;
    CData/*7:0*/ top__DOT__main1__DOT__r_y;
    CData/*7:0*/ top__DOT__main1__DOT__r_d;
    CData/*7:0*/ top__DOT__main1__DOT__r_wait;
    CData/*0:0*/ top__DOT__main1__DOT__r_st_we;
    CData/*0:0*/ __VdlyVal__top__DOT__r_clk__v0;
    CData/*0:0*/ __VdlySet__top__DOT__r_clk__v0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__r_clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ top__DOT__main1__DOT__r_st_wadr;
    SData/*15:0*/ top__DOT__main1__DOT__r_st_wdata;
    SData/*15:0*/ top__DOT__main1__DOT__vmem0__DOT__r_adr_p;
    SData/*15:0*/ top__DOT__main1__DOT__vmem0__DOT__r_dat_p;
    IData/*31:0*/ top__DOT__r_tc;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 65536> top__DOT__main1__DOT__vmem0__DOT__vmem;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
