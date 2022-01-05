// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// PSOD_Lipschitz_constraint1
arma::mat PSOD_Lipschitz_constraint1(int n, int m);
RcppExport SEXP _OAPB_PSOD_Lipschitz_constraint1(SEXP nSEXP, SEXP mSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type m(mSEXP);
    rcpp_result_gen = Rcpp::wrap(PSOD_Lipschitz_constraint1(n, m));
    return rcpp_result_gen;
END_RCPP
}
// PSOD_Finite_qnorm_1_constraint1
arma::mat PSOD_Finite_qnorm_1_constraint1(arma::mat X, int m);
RcppExport SEXP _OAPB_PSOD_Finite_qnorm_1_constraint1(SEXP XSEXP, SEXP mSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< int >::type m(mSEXP);
    rcpp_result_gen = Rcpp::wrap(PSOD_Finite_qnorm_1_constraint1(X, m));
    return rcpp_result_gen;
END_RCPP
}
// PSOD_Finite_qnorm_inf_constraint1
arma::mat PSOD_Finite_qnorm_inf_constraint1(int k, arma::mat x);
RcppExport SEXP _OAPB_PSOD_Finite_qnorm_inf_constraint1(SEXP kSEXP, SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type k(kSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(PSOD_Finite_qnorm_inf_constraint1(k, x));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_OAPB_PSOD_Lipschitz_constraint1", (DL_FUNC) &_OAPB_PSOD_Lipschitz_constraint1, 2},
    {"_OAPB_PSOD_Finite_qnorm_1_constraint1", (DL_FUNC) &_OAPB_PSOD_Finite_qnorm_1_constraint1, 2},
    {"_OAPB_PSOD_Finite_qnorm_inf_constraint1", (DL_FUNC) &_OAPB_PSOD_Finite_qnorm_inf_constraint1, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_OAPB(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
