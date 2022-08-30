# Rabbit Cipher

Rabbit is a software-efficient (profile 1), synchronous stream cipher using a 128-bit key and a 64-bit initialisation vector. A set of eight 32-bit state registers and eight 32-bit counters are used to provide an efficient encryption mechanism based on simple arithmetic and other basic operations such as rotation. Testing during the eSTREAM process confirmed that the cipher was among the most efficient stream ciphers submitted, and this efficiency was visible on a wide range of platforms. Like many stream ciphers, there is some marginal cost incurred during initialisation; this however has a minor impact on the total cost of encryption when encrypting short message streams. For more information about the stream cipher performance in software, refer to the [eSTREAM testing framework page](http://www.ecrypt.eu.org/stream/perf/#results).

![img](https://www.ecrypt.eu.org/stream/images/rabbit.png)

## Statement

copy from http://www.ecrypt.eu.org/stream/p3ciphers/rabbit/rabbit_p3source.zip

only changes c headers in order to use in arm64.


## Reference

- http://www.ecrypt.eu.org/stream/p3ciphers/rabbit/rabbit_p3.pdf
- https://www.ecrypt.eu.org/stream/e2-rabbit.html
- https://www.cryptopp.com/wiki/Rabbit