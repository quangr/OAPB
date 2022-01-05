# library(microbenchmark)
setup=function(){
  JuliaCall::julia_setup()
  funv1<<-JuliaCall::julia_eval("function funv1(X,m::Int)
         combo=collect(Iterators.flatten(map((x) -> (Iterators.product(x, x+1:m)),1:m-1)))
         commatrix=zeros(length(combo),m)
         commatrix.= broadcast((x,y,z)->(y[1]==z)-(y[2]==z),commatrix,combo,(1:m)')
         reduce(hcat,map(x->reduce(vcat,map(t->commatrix*t,x)), eachrow(X)))
end")
  funv2<<-JuliaCall::julia_eval("function funv2(X,m::Int)
         combo=collect(Iterators.flatten(map((x) -> (Iterators.product(x, x+1:m)),1:m-1)))
         commatrix=zeros(length(combo),m)
         commatrix.= broadcast((x,y,z)->(y[1]==z)-(y[2]==z),commatrix,combo,(1:m)')
         reduce(hcat,map(x->reduce(vcat,map(t->commatrix*t,x)), eachrow(X)))
end")

  invisible(JuliaCall::julia_call("funv1", matrix(c(1,2,3,4,5,6),nrow=3),3L))
  invisible(JuliaCall::julia_call("funv2", matrix(c(1,2,3,4,5,6),nrow=3),3L))
}
