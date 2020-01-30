/*
Jose Ibarra
1-25-2020

Lab Link: https://edabit.com/challenge/8NZaLdJBkhZCgNBc7

Lab Prompt:
    Phone Number Word Decoder
Create a program that converts a phone number with letters to one with only numbers.

Number	Letter
0	none
1	none
2	ABC
3	DEF
4	GHI
5	JKL
6	MNO
7	PQRS
8	TUV
9	WXYZ
Examples
textToNum("123-647-EYES") ➞ "123-647-3937"

textToNum("(325)444-TEST") ➞ "(325)444-8378"

textToNum("653-TRY-THIS") ➞ "653-879-8447"

textToNum("435-224-7613") ➞ "435-224-7613"
Notes
All inputs will be formatted as a string representing a proper phone number in the format XXX-XXX-XXXX or (XXX)XXX-XXXX, using numbers and capital letters.
Check the Resources tab for more info on telephone keypads.
*/

package Java;

public class PhoneNumberWord 
{   
    public static void main(String[] args) 
    {
        // Text different cases
        String ph1 = textToNum("123-647-EYES");
        String ph2 = textToNum("(325)444-TEST");
        String ph3 = textToNum("653-TRY-THIS");
        String ph4 = textToNum("435-224-7613");

        // Print out results
        System.out.println(ph1);
        System.out.println(ph2);
        System.out.println(ph3);
        System.out.println(ph4);
    }

    // textToNum function
    public static String textToNum(String phNumber)
    {   
        // replace specific characters with appropriate number
        phNumber = phNumber.replace('A', '2');
        phNumber = phNumber.replace('B', '2');
        phNumber = phNumber.replace('C', '2');

        phNumber = phNumber.replace('D', '3');
        phNumber = phNumber.replace('E', '3');
        phNumber = phNumber.replace('F', '3');

        phNumber = phNumber.replace('G', '4');
        phNumber = phNumber.replace('H', '4');
        phNumber = phNumber.replace('I', '4');

        phNumber = phNumber.replace('J', '5');
        phNumber = phNumber.replace('K', '5');
        phNumber = phNumber.replace('L', '5');

        phNumber = phNumber.replace('M', '6');
        phNumber = phNumber.replace('N', '6');
        phNumber = phNumber.replace('O', '6');

        phNumber = phNumber.replace('P', '7');
        phNumber = phNumber.replace('Q', '7');
        phNumber = phNumber.replace('R', '7');
        phNumber = phNumber.replace('S', '7');

        phNumber = phNumber.replace('T', '8');
        phNumber = phNumber.replace('U', '8');
        phNumber = phNumber.replace('V', '8');

        phNumber = phNumber.replace('W', '9');
        phNumber = phNumber.replace('X', '9');
        phNumber = phNumber.replace('Y', '9');
        phNumber = phNumber.replace('Z', '9');

        return phNumber;
    }
}