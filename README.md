# gtest-gmock-with-c

### Installation steps:

```
sudo apt-get install googletest
sudo apt-get install libgtest-dev

cd /usr/src/googletest/googletest
sudo cmake CMakeLists.txt
sudo make
sudo make install

cd /usr/src/googletest/googlemock
sudo cmake CMakeLists.txt
sudo make
sudo make install
```


### Application

**main -> module_a -> module_b**

1. **main** : Program to calculate the count of prime numbers in a range [0,n],
	  where n is passed as an input.
2. **module_a** : Takes end_interval(n) as input and iterates for all the numbers
              in the range [0,n] and checks if it prime.
	      api to check if a number is prime is provided by module_b.
3. **module_b** : Provides and integer as input and returns whether the number is prime or not. 
