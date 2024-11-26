<h2><a href="https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1">Nearly sorted</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array <strong>arr[]</strong>, where each element is at most <strong>k</strong> away from its target position, you need to sort the array optimally.</span></p>
<p><span style="font-size: 18px;">Note:&nbsp;<br></span></p>
<ol>
<li><span style="font-size: 18px;">The given Array can be <strong>Circular</strong>.</span></li>
<li><span style="font-size: 18px;">You need to change the given array <strong>arr[]</strong> in place.</span></li>
</ol>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [6, 5, 3, 2, 8, 10, 9], k = 3
<strong>Output: </strong>[2, 3, 5, 6, 8, 9, 10]<strong>
Explanation: </strong>The sorted array will be 2 3 5 6 8 9 10</span>
</pre>
<pre><span style="font-size: 14pt; font-family: 'andale mono', monospace;"><strong>Input:</strong><span style="color: rgb(29, 28, 29); font-variant-ligatures: common-ligatures; white-space: normal; background-color: rgb(248, 248, 248); --darkreader-inline-color: #d6d2cd; --darkreader-inline-bgcolor: #1c1e1f;" data-darkreader-inline-color="" data-darkreader-inline-bgcolor=""> arr[]= [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2</span>
<strong>Output: </strong>[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]<br><strong>Explanation: </strong>The sorted array will be 1 2 3 4 5 6 7 8 9 10</span></pre>
<p><span style="font-size: 18px;">DO NOT use the direct library sort() function for this question.</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ arr.size() ≤ 10<sup>6</sup><br>1 ≤ k &lt; arr.size()<br>1 ≤&nbsp;arr<sub>i </sub>≤ 10<sup>6</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Sorting</code>&nbsp;<code>Arrays</code>&nbsp;<code>priority-queue</code>&nbsp;