library(ROI)
library(purrr)
library(ggplot2)
pairdata=function(n,m=2){
  test=data.frame(x=rnorm(n),y=rnorm(n))
  map(1:(m-1),~test+data.frame(x=rnorm(n,sd = 0.05),y=rnorm(n,sd = 0.05)))%>%reduce(rbind,.init = test)
}
uniformdata=function(n){
  test=data.frame(x=runif(n,-1),y=runif(n,-1))
  test
}

RunSimulation=function(functionset,repeatnum=2,datagen=uniformdata,m=2,n=10){
  map(1:repeatnum,function(i){
    testseq=seq(m,n,m*2)
    data=datagen(testseq[length(testseq)])
    arrresult=map(functionset,~map(testseq,function(i){.x(data[1:i,])}))
    list(data=data,arrange=arrresult)
  })
}

# result=RunSimulation(list(PSOD.Finite.qnorm,partial(PSOD.Finite.qnorm,q=Inf),PSOD.RKHS))

PlotResult=function(fun=PSOD.Lipschitz,m=2){
  data=pairdata(5,m)
  ar1=matrix(fun(data,m=m),ncol = m,byrow = T)
  ggplot2::ggplot(data,ggplot2::aes(x=x,y=y,shape=as.factor(ar1)))+ggplot2::geom_point()
}




PlotCompare=function(result,treatmentfun=function(x,y){x+y}){
  curve=result%>%map(~map(.x$arrange,function(ars){
    treat1=treatmentfun(.x$data$x,.x$data$y)+1
    treat2=treatmentfun(.x$data$x,.x$data$y)
    map(ars,~mean(treat1[.x==1]-treat2[.x==2]))
  }))%>%transpose()%>%map(transpose)%>%map(~map(.x,~var(unlist(.x))))%>%map(unlist)
  reduce2(curve,1:length(curve),function(x,y,z){x+geom_line(mapping = aes(x = factor(1:length(y)), y = y,group=z))},.init = ggplot())
}


