<h1> COMP2412 - Assignment 3 </h1>

<h3> Question 1 </h3>

<h5> a) </h5>
<p> The difference between Big O and Big Θ notation is that Big O typically describes the worst case scenario of an algorithm's running time. It is the highest limit of the growth of the function describing the algorithm's running time. Big Θ is the algorithms precise running time and describes the growth of the function describing the algorithm's running time in that specific rate.</p>

<h5> b) </h5>
<h6> i) </h6>
<p> f(n) = n^2 + 3n + 2 and g(n) = 4n^2 + 2 </p>
<p> Drop Constants: f(n) = Θ(n^2) | g(n) = Θ(n^2) </p>
<p> Based on the time complexity of both functions, both f(n) and g(n) grow at the same rate. F(n) = Θg(n) </p>

<h6> ii) </h6>
<p> f(n) = 2^n and g(n) = n^5 </p>
<p> f(n) = Θ(2^n) | g(n) = Θ(n^5)</p>
<p> Based on the time complexity of both functions, f(n) grows at a slower rate than g(n). g(n) = O(f(n)) </p>

<h6> iii) </h6>
<p> f(n) = log(n) and g(n) = n </p>
<p> f(n) = Θ(log n) | g(n) = Θ(n) </p>
<p> 
Based on the time complexity of both algorithms, g(n) grows at a slower rate than f(n). Constant time functions grow at a slower rate than logarithmic functions. f(n) = O(g(n)) </p>

<h6> iv) </h6>
<p> f(n) = n! and g(n) = 2^n </p>
<p> f(n) = Θ(n!) | g(n) = Θ(2^n) </p>
<p> Based on the time complexity analysis, g(n) grows more slowly than f(n). f(n) = O(g(n)) </p>

<h5> c) </h5>
<p> For Code Refer to .cpp File(s) </p>

<h6> i), ii) & iii)</h6>
<img src="img/question_1.png" alt="Output of Question 1 c)">

<h3> Question 2 </h3>

<h5> a) </h5>
<p> For Code Refer to .cpp File(s)</p>

<h5> b) </h5>
<p> For Code Refer to .cpp File(s)</p>

<img src="img/question_2.1.png" alt="First Half of the Output of Question 2">
<img src="img/question_2.2.png" alt="Second Half of the Output of Question 2">

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

<h3> Question 3 </h3>

<p> For Code Refer to .cpp File(s) </p> 
<img src="img/question_3.png" alt="Output of Question 3"/>

<h3> Question 4 </h3>
<h5> a) </h5>
<p> For Code Refer to .cpp File(s) </p> 

<h5> b) </h5>
<p> For Code Refer to .cpp File(s) </p> 

<img src="img/question_4.png" alt="Output of Question 3"/>
