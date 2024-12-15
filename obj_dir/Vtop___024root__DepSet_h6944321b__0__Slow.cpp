// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__r_clk = 0U;
    vlSelfRef.top__DOT__r_tc = 0U;
    vlSelfRef.top__DOT__main1__DOT__r_x = 0U;
    vlSelfRef.top__DOT__main1__DOT__r_y = 0U;
    vlSelfRef.top__DOT__main1__DOT__r_d = 0U;
    vlSelfRef.top__DOT__main1__DOT__r_wait = 1U;
    vlSelfRef.top__DOT__main1__DOT__r_st_wadr = 0U;
    vlSelfRef.top__DOT__main1__DOT__r_st_we = 0U;
    vlSelfRef.top__DOT__main1__DOT__r_st_wdata = 0U;
    vlSelfRef.top__DOT__main1__DOT__vmem0__DOT__r_adr_p = 0U;
    vlSelfRef.top__DOT__main1__DOT__vmem0__DOT__r_dat_p = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge top.r_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge top.r_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->top__DOT__r_clk = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__r_tc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__main1__DOT__r_x = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__main1__DOT__r_y = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__main1__DOT__r_d = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__main1__DOT__r_wait = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__main1__DOT__r_st_wadr = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__main1__DOT__r_st_we = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__main1__DOT__r_st_wdata = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__main1__DOT__vmem0__DOT__r_adr_p = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__main1__DOT__vmem0__DOT__r_dat_p = VL_RAND_RESET_I(16);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->top__DOT__main1__DOT__vmem0__DOT__vmem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->__VdlyVal__top__DOT__r_clk__v0 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__top__DOT__r_clk__v0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__r_clk__0 = VL_RAND_RESET_I(1);
}
