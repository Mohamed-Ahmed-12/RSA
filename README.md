# RSA
RSA Encryption and Decryption Algorithm


Implement RSA Algorithm encryption and decryption using C++

### Input: 
1. Plain text of any size each character is changed to ASCII (X) and encrypted 

### Output: 
1. Cipher text in ASCII (decimal) for each character (X) 
2. Selected p,q for each character (X) 
3. Generated keys e,d for each character (X)
---------------------------------------------------------------

### Hint1:
- To do any exponentiation (x^H mod n) use Square and multiply algorithm

### Hint2: 
- For step 1 in key generation p & q must satisfy the following:- 
1. p, q are random numbers X < p, q <215 − 1 (where X is the ASCII (decimal) of one character in plaintext) 
2. p, q are prime numbers (Test primality of them using Fermat Primality Test mentioned below ) 
- For step 4 and 5 in key generation use Extended Euclidean Algorithm OR Binary Extended Euclidean Algorithm

### Hint3: 
1. Step 1: s = 100 
- Step 1.2: is computed by using the square-and-multiply algorithm

### Hint4 in Encryption: 
- Compute Exponentiation (xe mod n) using Square and Multiply method

### Hint5 in Decryption:- 
1. Compute exponentiation using square and multiply method. 
2. Compute cp and cq using EEA OR Binary EEA.
### Decryption using Chinese Remainder Theorem (CRT)
