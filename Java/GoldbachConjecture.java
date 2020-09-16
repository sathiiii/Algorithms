/* 
  Gold bach's conjecture: Every integer greater than 2 can be written as the sum of three primes
  Gold bach's weak conjecture: Every odd number greater than 5 can be expressed as the sum of three primes
*/

import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Solution {
    // Sieve of Eratosthenes
    public static boolean[] sieve(int n) {
        boolean prime[] = new boolean[n + 1]; 
        for(int i = 0; i < n; i++) 
            prime[i] = true; 
        for(int p = 2; p * p <= n; p++) 
        {
            if(prime[p] == true) 
            {
                for(int i = p * 2; i <= n; i += p) 
                    prime[i] = false; 
            } 
        }
        return prime;
    }
    
    public static void main(String[] args) {
        // Since N is odd, assume the first prime is always 3. Then for an i such that both i and N - 3 - i are primes.
        Scanner sc=new Scanner(System.in);
        long N = sc.nextLong();
        StringBuffer sb = new StringBuffer();
        if (N <= Integer.MAX_VALUE / 10) {
            N -= 3;
            sb.append("3 ");
            int n = (int) N;
            boolean[] isPrime = sieve((int) n);
            for (int i = 2; i < n; i++)
                if (isPrime[i] && isPrime[n - i]) {
                    sb.append(i + " " + (n - i));
                    break;
                }
        }
        else {
            BigInteger n = BigInteger.valueOf(N);
            BigInteger xxx = n.subtract(new BigInteger("1000000"));
            BigInteger nn = xxx.nextProbablePrime();
            n = n.subtract(nn);
            // Upper bound for x
            int xx = Integer.parseInt(n.toString());
            sb.append(nn.toString() + " ");
            boolean[] isPrime = sieve(xx);
            for (int x = 2; x < xx; x++)
                if (isPrime[x] && isPrime[xx - x]) {
                    sb.append(x + " " + (xx - x));
                    break;
                }
        }
        System.out.println(sb.toString());
    }
}
