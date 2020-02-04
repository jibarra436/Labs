/*
    Name: Jose Ibarra
    Date: 1-30-2020

    Lab Link: https://edabit.com/challenge/c52kNwPuWo5kp9x4H
*/

package Java;

public class Switcharoo 
{   
    public static void main(String[] args) 
    {
        // print out test cases
        System.out.println(flipEndChars("Cat, dog, and mouse."));
        System.out.println(flipEndChars("ada"));
        System.out.println(flipEndChars("Ada"));
        System.out.println(flipEndChars("z"));
    }

    // flipEndChars function definition
    public static String flipEndChars(String s)
    {
        // if the length is < 2
        if(s.length() < 2)
            return "Incompatible";
        // if the first and last char are the same
        else if(s.charAt(0) == s.charAt(s.length()-1))
            return "Two's a pair.";
        // otherwise, switch first and last char
        else 
        {
            char first = s.charAt(0);
            char last = s.charAt(s.length()-1);

            return last + s.substring(1, s.length()-1) + first;
        }
	}
}