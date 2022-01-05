#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;


// [[Rcpp::export]]
arma::mat PSOD_Finite_qnorm_inf_constraint1(int k,arma::mat x){
  int n=k*(k-1)/2;
  mat order(n,2);
  int kk=0;
  for(int i=1;i<k+1;i+=1){
    for(int j=i+1;j<k+1;j+=1){
      order(kk,0)=i;
      order(kk,1)=j;
      kk+=1;
    }
  }
  mat A(n,k,fill::zeros);
  for(int i=0;i<n;i+=1){
    A(i,order(i,0)-1)=1;
    A(i,order(i,1)-1)=-1;
  }
  int xn=x.n_cols;
  cube c(n,k*x.n_rows,xn);
  for(int i=0;i<xn;i+=1){
    mat V=x(0,i)*A;
    for(int j=1;j<x.n_rows;j+=1){
      V=join_rows(V,x(j,i)*A);
    }
    c.slice(i)=V;
  }

  mat re(n,k*x.n_rows,fill::zeros);
  for(int i=0;i<xn;i+=1){
    re-=c.slice(i);
  }
  for(int i=1;i<pow(2,xn);i++){
    mat temp(n,k*x.n_rows,fill::zeros);
    int num=i;
    for(int j=0;j<xn;j++){
      if (num%2==1){temp+=c.slice(xn-j-1);}
      else {temp-=c.slice(xn-j-1);}
      num/=2;
    }
    re=join_cols(re,temp);
  }
  return re;


}


