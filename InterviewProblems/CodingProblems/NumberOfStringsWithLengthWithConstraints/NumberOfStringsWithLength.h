/**
 * Solves problem with original statement at: http://www.geeksforgeeks.org/count-strings-can-formed-using-b-c-given-constraints/
 *
 * Given a length n, count the number of strings of length n that can be made using ‘a’, ‘b’ and ‘c’ with at-most one ‘b’ and two ‘c’s allowed.

    Examples:

    Input : n = 3
    Output : 19
    Below strings follow given constraints:
    aaa aab aac aba abc aca acb acc baa
    bac bca bcc caa cab cac cba cbc cca ccb

    Input  : n = 4
    Output : 39
 */

#ifndef SERGIOTEST_NUMBEROFSTRINGSWITHLENGTH_H
#define SERGIOTEST_NUMBEROFSTRINGSWITHLENGTH_H

//Time complexity: O(1), Space complexity: O(1)
int numberOfStringsWithLength(int length) {
    int temp = length * (length-1);
    return 2*length + temp + temp/2 + (temp*(length-2))/2 + 1;
}
/**
  Logic behind solution

  There are six cases when building a string:

       1) You use 1 b
       2) You use 1 c
       3) You use 1 b and 1 c
       4) You use 2 c
       5) You use 1 b and 2 c
       6) You don't use any b or c, only a

   In each of them, you can think of the string you're trying to count the combinations of as already
   having length N. There are N! ways you can reorder a sequence of N unique characters. However, that
   doesn't happen in any case, so we'll have to modify the base expression to count reorderings of each of them.

        1) You use 1 b: In this case, you have a string of length N where N-1 characters are identical.
        This means there are N!/(N-1)! = N permutations of this string. To know more about why this is true,
        search for "permutations with identical objects" in Google. I had a link that explained this topic
        with awesome and concise detail, but I lost it; I'll put it here if I find it again. Sorry.
        2) You use 1 c: Using the same logic from case (1), we find that there are N!/(N-1)! = N permutations
        of this string.

    So far, we've realized that a string with length N with the given conditions has N permutations because of
    case 1 and N permutations because of case 2. That's a total of 2*N permutations so far. Let's see the other
    cases:

        3) You use 1 b and 1 c: Now, we have a string of length N for which N-2 characters are identical.
        That means there are N!/(N-2)! = N(N-1) permutations of this string.
        4) You use 2 c: This time, we not only have a string of length N in which N-2 characters are identical,
        but in which also 2 other characters are also identical amongst them. Because of that, there are
        N!/((N-2)!*2!) = N(N-1)/2 sequence permutations in case 4.
        5) You use 1 b and 2 c: There are N-3 identical elements in this sequence of length N. On top of that,
        2 of the 3 non-identical characters are identical amongst them. Because of this, in this case there are
        N!/((N-3)!*2!) = N(N-1)(N-2)/2 permutations for this sequence.
        6) N identical characters in a sequence of length N means there's N!/N! = 1 permutation for case 6. You
        can visualize this as a string of only a "aaaaaaaaaaaaaaaaaaaaa".

     Adding the permutations from all cases, our formula for the total amount of strings with length N is:

     totalAmount = 2(N) + N(N-1) + N(N-1)/2 +  N(N-1)(N-2)/2 + 1.

     We could code this as-is, but since we need the result from the operation N(N-1) several times in the
     equation, I saved it in a temporal variable. Replacing N(N-1) with temp, the formula becomes:

     totalAmount = 2(N) + temp + temp/2 + temp(N-2)/2 + 1

     Which is exactly what my code returns.
 */

#endif //SERGIOTEST_NUMBEROFSTRINGSWITHLENGTH_H
