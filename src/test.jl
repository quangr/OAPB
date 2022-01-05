function fun1(X,m::Int)
  combo=map((x) -> Iterators.product(x, x+1:m),1:m-1)
  commatrix=map((v)->begin
               t=map((x)->begin
                 x
                 t =zeros(1,m)
                    t[x[1]]= 1
                    t[x[2]]= (-1)
                    t
                   end,v)
               reduce(vcat,t)
               end,combo)          |>t->             reduce(vcat,t)
  hvcat(tuple(ones(Int,size(X)[1])*size(X)[2]...),map((x)->x*commatrix, X)...)
end



function funv2(X,m::Int)
         combo=collect(Iterators.flatten(map((x) -> (Iterators.product(x, x+1:m)),1:m-1)))
         commatrix=zeros(length(combo),m)
         commatrix.= broadcast((x,y,z)->(y[1]==z)-(y[2]==z),commatrix,combo,(1:m)')
         reduce(hcat,map(x->reduce(vcat,map(t->commatrix*t,x)), eachrow(X)))
end