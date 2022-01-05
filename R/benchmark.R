library(microbenchmark)

# testResult = microbenchmark(PSOD.Finite.qnorm.1.constraint1(matrix(c(1,2,3,4,5,6),nrow=3),3),
#                             func2(matrix(c(1,2,3,4,5,6),nrow=3),3),julia_call("funv2", matrix(c(1,2,3,4,5,6),nrow=3),3L), times = 10)
#
# julia_source("./test.jl")
# invisible(julia_call("funv2", matrix(c(1,2,3,4,5,6),nrow=3),3L))
# julia_call("fun1", matrix(c(1,2,3,4,5,6),nrow=3),3L)
