.name           "Tester"
.comment        "Just a test"

start:

#defens

st r1, 7
ld  %0, r1
ld  %16777216, r5
st  r5, -18
ld	%17002497, r2
ld	%57672449, r3
ld	%16777216, r4
fork %:gogo
ld	%0, r7

def:

st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r1, 6
live %0
st	r1, 6
live %0
st	r1, 6
live %0
fork %500
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r1, 6
live %0
st	r1, 6
live %0
st	r1, 6
live %0
st	r1, 6
live %0
st	r1, 6
live %0
st	r1, 6
live %0
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511
st	r5, -507
st	r1, -511

gogo:

st	r1, 6
live %0
zjmp %:start
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r3, 256
st r4, 256
st r1, 252
#end defens
