# RNAbpp
Just report base pairing probabilities (BPPs) with some formats.

This is the simplest example. BPPs are calculated with Turner ('04) model by default.
```
$ bpp -s CGUACGUAGC
0 6 0.003314395747691672 
0 9 0.0046116692515848576 
1 7 0.00021516250108673767 
2 8 0.00033403390693030719 
2 9 0.019995303866167494 
4 9 0.00090769337836225266
```

Following will show the same results with what RNAfold reports (and kindly wraps in dot.ps) except for the index origin.
```
build/bpp -s CGUACGUUAGCAGCCUAGCUG -q -g 1e-6
```

Other options are also available. 

"max BP span" constraint.
```
$ bpp -s CGUACGUAGC -m 5
4 9 0.00093209700102018774
```

Report in python's 2D list format.
```
$ bpp -s CGUACGUAGC -p
[[0,0,0,0,0,0,0.003314395747691672,0,0,0.0046116692515848576],[0,0,0,0,0,0,0,0.00021516250108673767,0,0],[0,0,0,0,0,0,0,0,0.00033403390693030719,0.019995303866167494],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0.00090769337836225266],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0]]
```
