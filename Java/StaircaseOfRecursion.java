/*
    Name: Jose Ibarra
    Date: 1-30-2020

    Lab Link: https://edabit.com/challenge/YuZYMkwnJpALmHELB
*/

package Java;

public class StaircaseOfRecursion 
{   
    public static void main(String[] args) 
    {
        // print out test cases
        System.out.println(waysToClimb(0));
        System.out.println(waysToClimb(1));
        System.out.println(waysToClimb(2));
        System.out.println(waysToClimb(5));
        System.out.println(waysToClimb(10));
    }

    // waysToClimb function definition
    public static int waysToClimb(int num)
    {
        // find (num+1)th fib number
        return fibonacci(num + 1);
    }

    // fibonacci number function to find nth fib number
    public static int fibonacci(int n)
    {
        // base case
        if(n <= 1)
            return n;
        else // continue fib sequence
            return fibonacci(n - 1) + fibonacci(n - 2);
    }
}