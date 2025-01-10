This is a sample project I ran out of curiosity. 

I wondered what is faster: performing a linear regression using Gram-Schmidt QR decomposotion 
or using gradient descent.

What I found was that the gradient descent ran 84 times slower than the Graam-Schmidt process.
The dataset I ran this on was the Boston Housing dataset. I only tested the processes on one
independent variable, "dis", and my dependent variable was "medv." The times I got could be 
drastically different when expanding the number of independent variables. 

The learning rate could also make changes to the time spent for gradient descnet. However, 
I felt that this requires knowing what the actual beta values should be. This leads to additional
time that the user has to spend adjusting input parameters.

Overall, from this experiment, I've found that in the 2 dimensional case, QR decomposition far
outperforms gradient descent in obtaining a regression line. Further code changes and testing will
need to be done to see how true this is in higher dimension datasets.