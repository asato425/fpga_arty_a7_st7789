// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VlCoroutine Vtop___024root___eval_initial__TOP__Vtiming__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__r_clk__0 
        = vlSelfRef.top__DOT__r_clk;
}

VL_INLINE_OPT VlCoroutine Vtop___024root___eval_initial__TOP__Vtiming__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0xaULL, 
                                             nullptr, 
                                             "top.v", 
                                             9);
        vlSelfRef.__VdlyVal__top__DOT__r_clk__v0 = 
            (1U & (~ (IData)(vlSelfRef.top__DOT__r_clk)));
        vlSelfRef.__VdlySet__top__DOT__r_clk__v0 = 1U;
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vdly__top__DOT__main1__DOT__r_x;
    __Vdly__top__DOT__main1__DOT__r_x = 0;
    CData/*7:0*/ __Vdly__top__DOT__main1__DOT__r_y;
    __Vdly__top__DOT__main1__DOT__r_y = 0;
    CData/*7:0*/ __Vdly__top__DOT__main1__DOT__r_wait;
    __Vdly__top__DOT__main1__DOT__r_wait = 0;
    CData/*7:0*/ __Vdly__top__DOT__main1__DOT__r_d;
    __Vdly__top__DOT__main1__DOT__r_d = 0;
    SData/*15:0*/ __VdlyVal__top__DOT__main1__DOT__vmem0__DOT__vmem__v0;
    __VdlyVal__top__DOT__main1__DOT__vmem0__DOT__vmem__v0 = 0;
    SData/*15:0*/ __VdlyDim0__top__DOT__main1__DOT__vmem0__DOT__vmem__v0;
    __VdlyDim0__top__DOT__main1__DOT__vmem0__DOT__vmem__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__main1__DOT__vmem0__DOT__vmem__v0;
    __VdlySet__top__DOT__main1__DOT__vmem0__DOT__vmem__v0 = 0;
    // Body
    if (VL_UNLIKELY((0x2625a00U <= vlSelfRef.top__DOT__r_tc))) {
        VL_WRITEF_NX("@Dfin\n\nSimulation time out specified by MAX_CYCLES(%0#)\n\n",0,
                     32,vlSelfRef.top__DOT__r_tc);
        VL_FINISH_MT("top.v", 24, "");
    }
    __Vdly__top__DOT__main1__DOT__r_x = vlSelfRef.top__DOT__main1__DOT__r_x;
    __Vdly__top__DOT__main1__DOT__r_y = vlSelfRef.top__DOT__main1__DOT__r_y;
    __Vdly__top__DOT__main1__DOT__r_wait = vlSelfRef.top__DOT__main1__DOT__r_wait;
    __Vdly__top__DOT__main1__DOT__r_d = vlSelfRef.top__DOT__main1__DOT__r_d;
    __VdlySet__top__DOT__main1__DOT__vmem0__DOT__vmem__v0 = 0U;
    vlSelfRef.top__DOT__r_tc = ((IData)(1U) + vlSelfRef.top__DOT__r_tc);
    __Vdly__top__DOT__main1__DOT__r_x = ((0xefU == (IData)(vlSelfRef.top__DOT__main1__DOT__r_x))
                                          ? 0U : (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.top__DOT__main1__DOT__r_x))));
    __Vdly__top__DOT__main1__DOT__r_y = (((0xefU == (IData)(vlSelfRef.top__DOT__main1__DOT__r_y)) 
                                          & (0xefU 
                                             == (IData)(vlSelfRef.top__DOT__main1__DOT__r_x)))
                                          ? 0U : (0xffU 
                                                  & ((0xefU 
                                                      == (IData)(vlSelfRef.top__DOT__main1__DOT__r_x))
                                                      ? 
                                                     ((IData)(1U) 
                                                      + (IData)(vlSelfRef.top__DOT__main1__DOT__r_y))
                                                      : (IData)(vlSelfRef.top__DOT__main1__DOT__r_y))));
    if (((0U == (IData)(vlSelfRef.top__DOT__main1__DOT__r_y)) 
         & (0U == (IData)(vlSelfRef.top__DOT__main1__DOT__r_x)))) {
        __Vdly__top__DOT__main1__DOT__r_wait = ((0xaU 
                                                 <= (IData)(vlSelfRef.top__DOT__main1__DOT__r_wait))
                                                 ? 1U
                                                 : 
                                                (0xffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelfRef.top__DOT__main1__DOT__r_wait))));
        if ((1U == (IData)(vlSelfRef.top__DOT__main1__DOT__r_wait))) {
            __Vdly__top__DOT__main1__DOT__r_d = (0xffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelfRef.top__DOT__main1__DOT__r_d)));
        }
    }
    if (vlSelfRef.top__DOT__main1__DOT__r_st_we) {
        if (VL_UNLIKELY((vlSelfRef.top__DOT__main1__DOT__vmem0__DOT__vmem
                         [vlSelfRef.top__DOT__main1__DOT__r_st_wadr] 
                         != (IData)(vlSelfRef.top__DOT__main1__DOT__r_st_wdata)))) {
            VL_WRITEF_NX("@D%0#_%0#\n",0,16,((IData)(vlSelfRef.top__DOT__main1__DOT__r_st_wadr) 
                                             ^ (IData)(vlSelfRef.top__DOT__main1__DOT__vmem0__DOT__r_adr_p)),
                         16,((IData)(vlSelfRef.top__DOT__main1__DOT__r_st_wdata) 
                             ^ (IData)(vlSelfRef.top__DOT__main1__DOT__vmem0__DOT__r_dat_p)));
            Verilated::runFlushCallbacks();
            __VdlyVal__top__DOT__main1__DOT__vmem0__DOT__vmem__v0 
                = vlSelfRef.top__DOT__main1__DOT__r_st_wdata;
            __VdlyDim0__top__DOT__main1__DOT__vmem0__DOT__vmem__v0 
                = vlSelfRef.top__DOT__main1__DOT__r_st_wadr;
            __VdlySet__top__DOT__main1__DOT__vmem0__DOT__vmem__v0 = 1U;
            vlSelfRef.top__DOT__main1__DOT__vmem0__DOT__r_adr_p 
                = vlSelfRef.top__DOT__main1__DOT__r_st_wadr;
            vlSelfRef.top__DOT__main1__DOT__vmem0__DOT__r_dat_p 
                = vlSelfRef.top__DOT__main1__DOT__r_st_wdata;
        }
    }
    vlSelfRef.top__DOT__main1__DOT__r_wait = __Vdly__top__DOT__main1__DOT__r_wait;
    if (__VdlySet__top__DOT__main1__DOT__vmem0__DOT__vmem__v0) {
        vlSelfRef.top__DOT__main1__DOT__vmem0__DOT__vmem[__VdlyDim0__top__DOT__main1__DOT__vmem0__DOT__vmem__v0] 
            = __VdlyVal__top__DOT__main1__DOT__vmem0__DOT__vmem__v0;
    }
    vlSelfRef.top__DOT__main1__DOT__r_st_we = 1U;
    vlSelfRef.top__DOT__main1__DOT__r_st_wadr = (((IData)(vlSelfRef.top__DOT__main1__DOT__r_y) 
                                                  << 8U) 
                                                 | (IData)(vlSelfRef.top__DOT__main1__DOT__r_x));
    vlSelfRef.top__DOT__main1__DOT__r_st_wdata = ((
                                                   ((IData)(vlSelfRef.top__DOT__main1__DOT__r_x) 
                                                    < (IData)(vlSelfRef.top__DOT__main1__DOT__r_d)) 
                                                   & ((IData)(vlSelfRef.top__DOT__main1__DOT__r_y) 
                                                      < (IData)(vlSelfRef.top__DOT__main1__DOT__r_d)))
                                                   ? 0xffffU
                                                   : 
                                                  (((IData)(vlSelfRef.top__DOT__main1__DOT__r_x) 
                                                    < (IData)(vlSelfRef.top__DOT__main1__DOT__r_y))
                                                    ? 0x7e0U
                                                    : 0x1fU));
    vlSelfRef.top__DOT__main1__DOT__r_d = __Vdly__top__DOT__main1__DOT__r_d;
    vlSelfRef.top__DOT__main1__DOT__r_x = __Vdly__top__DOT__main1__DOT__r_x;
    vlSelfRef.top__DOT__main1__DOT__r_y = __Vdly__top__DOT__main1__DOT__r_y;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__top__DOT__r_clk__v0) {
        vlSelfRef.__VdlySet__top__DOT__r_clk__v0 = 0U;
        vlSelfRef.top__DOT__r_clk = vlSelfRef.__VdlyVal__top__DOT__r_clk__v0;
    }
}

void Vtop___024root___timing_resume(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___timing_resume\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___timing_resume(vlSelf);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("top.v", 8, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("top.v", 8, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
