<h1> COMP2412 - Assignment 3 </h1>

<h3> Question 1 </h3>

<h5> a) </h5>
<p> The difference between Big O and Big Θ (Theta) notation in algorithm analysis is that Big O describes an upper limit on the growth rate of an algorithm's running time. Big O shows the maximum rate at which an algorithm’s time can increase and is often typically the algorithm’s worst-case scenario,. Big Θ (Theta) specifies the tight bound for an algorithm’s growth rate based on the code’s input size and provides a precise measure of an algorithm’s running time growth at that specific rate. </p>


<h5> b) </h5>
<h6> i) </h6>
<p> f(n) = n^2 + 3n + 2 and g(n) = 4n^2 + 2 </p>

<h6> ii) </h6>
<p> </p>

<h6> iii) </h6>
<p> </p>

<h5> c) </h5>
<p> For Code Refer to .cpp File(s) </p>

<h6> i), ii) & iii)</h6>
<img src="img/question_1.png" alt="Output of Question 1 c)">

<h3> Question 2 </h3>

<h5> a) </h5>
<p> For Code Refer to .cpp File(s)</p>

<h5> b) </h5>
<p> For Code Refer to .cpp File(s)</p>

<img src="img/question_2.1.png.png" alt="First Half of the Output of Question 2">
<img src="img/question_2.2.png.png" alt="Second Half of the Output of Question 2">

<h5> c) </h5>
<p> Building Sorted Array: </p>
<ul> 
    <li> Input => Array of Values </li>
    <li> Size of Input => n </li>
    <li> Basic Operation => FixMinNode(); </li>
    <li> # of BO => n</li>
    <li> Complexity => θ(n) </li>
</ul>

<p> ExtractMin(): </p>
<ul> 
    <li> Input => Array of Values </li>
    <li> Size of Input => n </li>
    <li> Basic Operation => FixMinNode(); </li>
    <li> # of BO => θ(logn) </li>
    <li> Complexity => θ(logn) </li>
</ul>

<p> Heap Sort => θ( θ(n) * θ(logn) ) => θ(nlogn) </p>