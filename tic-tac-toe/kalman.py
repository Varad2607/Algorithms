from math import*


def function(mu,sigma2,x):

    return 1/sqrt(2.*pi*sigma2)*exp(-.5*(x-mu)**2/sigma2)


print (function(10.,4.,8.))
