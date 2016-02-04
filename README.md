# Boggle
A boggle solver written in c++

* Can use arbitrary dice -- Original, updated, big boggle, and boggle deluxe dice are hard coded in there as well
* Can use arbitrary dictionaries -- Using sowpods by default.
* Solution class can score using boggle or big boggle rules, or scrabble values
* Can solve arbitrary sized square boggle boards -- for instance, a 32x32 board 

<pre>
 C   S   R   N   O   U   T   T   N   I   A   T   R   L   E   G   R   K   I   T   E   Y   H   T   X   A   R   W   D   N   M   N
 K   R   T   L   S   R   S   E   E   V   H   T   K   T   O   I   H   E   S   D   S   T   A   W   I   E   N   P   S   F   R   F
 P   R   M   J   R   Y   D   L   O   N   C   N   N   H   M   J   E   T   L   A   N   E   A   G   V   R   V   O   I   J   E   C
 R   C   H   O   I   E   I   N   R   A   O   T   H   D   Y   U   N   Y   O   E   T   I   H   G   T   Y   E   I   N   H   T   I
 E   H   T   E   B   A   T   O   H   S   S   H   H   H   L   I   S   A   T   M   S   X   A   N   L   L   D   R   E   D   E   F
 R   L   U   O   O   E   E   Y   R   E   E   O   O   L   V   E   H   Qu  E   O   L   G   L   A   V   H   O   A   F   I   E   W
 M   O   F   K   O   A   U   G   D   G   W   H   H   C   N   L   S   T   I   E   N   N   U   P   Qu  R   R   U   T   E   N   L
 W   O   F   S   F   O   I   N   U   I   K   D   N   V   E   N   E   C   A   T   A   I   H   M   G   H   O   W   N   E   N   E
 C   U   O   S   R   T   I   N   A   Y   N   E   E   T   D   J   S   Y   Z   H   I   Z   R   E   I   F   D   D   N   A   N   W
 O   A   Qu  L   E   E   S   C   L   E   N   V   C   H   M   L   E   S   A   R   R   Y   R   E   R   E   E   U   R   S   E   N
 E   Y   C   M   I   M   S   E   O   T   E   E   S   I   F   L   G   S   N   R   E   A   R   T   S   S   C   E   A   T   A   O
 R   A   L   E   O   S   L   H   K   B   M   A   R   K   H   G   O   B   A   N   C   E   N   C   E   H   T   L   S   O   O   D
 A   E   T   W   V   R   S   A   E   T   O   E   L   T   T   U   R   N   S   T   F   E   R   O   W   E   D   O   H   K   T   S
 A   A   G   R   T   A   G   T   R   D   T   W   A   Qu  S   T   L   L   W   L   O   L   I   K   L   O   T   D   N   E   U   T
 Z   W   E   E   N   L   O   R   S   N   X   N   L   S   M   E   S   T   T   D   R   A   I   T   D   I   T   I   H   I   N   E
 H   M   T   E   N   L   I   L   U   R   E   D   V   I   T   W   N   Z   E   H   C   T   B   C   I   G   W   P   L   O   A   I
 F   T   N   I   E   A   H   N   E   W   E   E   R   I   F   J   T   R   O   W   N   O   O   D   O   G   I   B   S   M   W   Z
 L   L   G   L   S   D   I   R   P   A   T   Y   O   R   F   S   H   E   N   Y   H   O   A   S   E   O   E   E   A   O   R   N
 Y   U   B   N   O   E   V   P   E   Y   E   O   M   E   H   A   X   P   E   J   O   R   T   Y   S   E   E   R   R   I   H   A
 C   E   E   T   L   T   N   H   Qu  H   S   L   O   D   A   T   E   U   E   C   A   O   S   T   T   T   D   L   N   T   E   E
 E   U   Qu  S   W   W   T   S   N   Qu  K   T   V   S   O   B   N   I   I   E   D   D   K   O   E   E   O   N   T   Z   I   E
 O   E   E   O   T   L   T   C   A   R   T   E   R   Y   R   N   A   N   J   G   O   E   J   H   S   R   M   R   D   W   J   M
 F   E   D   R   A   T   T   N   E   P   O   I   E   N   W   N   C   Y   T   A   N   I   Y   B   H   S   E   N   T   E   V   B
 H   W   A   F   N   T   O   I   H   F   N   L   E   T   A   M   T   X   P   A   I   U   Y   E   D   Qu  Qu  T   A   P   A   E
 S   I   B   E   S   E   E   S   U   A   A   U   O   A   R   Y   E   E   U   R   U   M   I   X   O   A   A   I   Qu  S   H   A
 C   L   A   D   V   O   H   O   O   R   O   I   E   I   L   S   O   Y   E   O   M   R   I   N   T   Y   N   J   M   F   H   O
 H   O   D   A   T   T   O   B   W   R   M   O   E   L   E   G   O   O   Y   E   R   I   O   A   I   U   K   K   I   X   A   I
 T   O   E   S   I   A   D   Y   B   T   G   Qu  Z   T   V   S   Y   E   S   D   A   S   S   U   I   A   W   L   S   L   T   T
 O   S   Y   E   H   U   T   E   A   E   P   M   L   E   T   S   T   S   T   I   A   O   A   L   X   E   B   M   E   T   A   A
 H   F   I   D   F   L   L   G   I   E   A   O   N   L   E   P   B   D   E   O   O   G   N   O   S   B   A   Z   E   W   O   Y
 S   R   R   E   T   G   R   R   M   N   E   T   K   A   O   G   G   R   S   I   O   G   O   A   T   G   C   W   O   O   S   R
 Y   L   E   A   Y   E   E   O   N   P   I   K   O   U   H   W   X   E   A   O   G   H   R   N   T   S   R   P   E   T   H   H
Words: 17305  Points: 57083
Longest: ORIENTEERINGS, REENLISTMENTS
         AAH(1)       AAHED(2)        AAHS(1)         AAL(1)        AALS(1)
         AAS(1)         ABA(1)        ABAC(1)       ABACS(2)        ABAS(1)
       ABATE(2)      ABATOR(3)     ABATORS(5)         ABB(1)        ABBA(1)
...
</pre>
