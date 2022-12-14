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

### Hint 1:
- To do any exponentiation (x^H mod n) use Square and multiply algorithm

### Hint 2: 
- For step 1 in key generation p & q must satisfy the following:- 
1. p, q are random numbers X < p, q <215 − 1 (where X is the ASCII (decimal) of one character in plaintext) 
2. p, q are prime numbers (Test primality of them using Fermat Primality Test mentioned below ) 
- For step 4 and 5 in key generation use Extended Euclidean Algorithm OR Binary Extended Euclidean Algorithm

### Hint 3: 
1. Step 1 : s = 100 
- Step 1.2 : is computed by using the square-and-multiply algorithm

### Hint 4 in Encryption: 
- Compute Exponentiation (x^e mod n) using Square and Multiply method

### Hint 5 in Decryption:- 
1. Compute exponentiation using square and multiply method. 
2. Compute cp and cq using EEA OR Binary EEA.
### Decryption using Chinese Remainder Theorem (CRT)

### Example
![14 12 2022_15 16 22_REC](https://user-images.githubusercontent.com/84830168/207608882-961fc512-b3d5-43c9-a68e-ea2a6fc1ff3a.png)
