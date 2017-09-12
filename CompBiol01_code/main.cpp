#include <iostream>
#include <cmath>
#include <iomanip>
#include "RandomVariable.h"

/* This program implements the Metropolis-Hastings (MH) algorithm for the
   coin tossing problem. The steps of the MH algorith are:
   
   1. Call the current state of the Markov chain theta. If this is the first
      cycle of the chain, then initialize theta to some value.
   2. Propose a new value for theta, called thetaPrime. This proposal mechanism
      is at the discretion of the programmer. However, several rules must be 
      followed. The proposal mechanism should involve random numbers. You should
      be able to calculate q(theta -> thetaPrime) and the imagined reverse move
      q(thetaPrime -> theta). Also, the proposal mechanism can't result in a periodic
      or reducible chain, which are in practice easy to accomplish. 
   3. Calculate the probability of accepting thetaPrime as the next state of the chain:
   
      R = min(1, likelihood ratio X prior ratio X proposal ratio)

   4. Generate a uniform(0,1) rv called u. If u < R, then set theta = thetaPrime. O/w
      the chain remains in state theta.
   5. Go to Step # 2.
*/


int main(int argc, const char * argv[]) {

    // instantiate our random number object
    RandomVariable rv;

    // user interface
    int numHeads = 43;
    int numTails = 57;
    int chainLength = 1000000;
    double window = 0.1;
    int bins[100];
    for (size_t i=0; i<100; i++)
        bins[i] = 0;
    
    double theta = rv.uniformRv();  // step 1
    for (size_t n=1; n<=chainLength; n++)
        {
        std::cout << n << " -- " << theta << " -> ";
        // step 2
        double thetaPrime = theta + (rv.uniformRv() - 0.5) * window;
        if (thetaPrime < 0.0)
            thetaPrime = -thetaPrime;
        else if (thetaPrime > 1.0)
            thetaPrime = 2.0 - thetaPrime;
            
        // step 3
        double lnLikelihoodRatio = (numHeads * log(thetaPrime) + numTails * log(1.0-thetaPrime)) -
                                   (numHeads * log(theta     ) + numTails * log(1.0-theta     ));
        double lnPriorRatio = 0.0;
        double lnProposalRaio = 0.0;
        double lnR = lnLikelihoodRatio + lnPriorRatio + lnProposalRaio;
        double R = 0.0;
        if (lnR < -300.0)
            R = 0.0;
        else if (lnR > 0.0)
            R = 1.0;
        else
            R = exp(lnR);
            
        std::cout << thetaPrime << std::endl;;
        
        // step 4
        double u = rv.uniformRv();
        if (u < R)
            theta = thetaPrime;
            
        bins[(int)(theta*100.0)]++;
        }
    
    // print the frequency histogram
    double sum = 0.0;
    for (size_t i=0; i<100; i++)
        {
        sum += (double)bins[i] / chainLength;
        std::cout << std::fixed << std::setprecision(2) << i*0.01 << "-" << (i+1)*0.01 << " -- ";
        std::cout << std::fixed << std::setprecision(4) << (double)bins[i] / chainLength << " ";
        std::cout << std::fixed << std::setprecision(4) << sum << " ";
        std::cout << std::endl;
        }

    return 0;
}
