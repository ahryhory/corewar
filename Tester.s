.name           "Tester"
.comment        "Just a tester"

ld %88, r2
ld %89, r3
ld %85, r4
ld %0, r5
aff		r2
aff		r3
aff		r4
zjmp %-40
live %42
aff		r1
aff		r1
aff		r1
aff		r1
live %42
aff r1
aff r1
# ld	%0, r1
# zjmp	%-20
# live	%228
# live	%228
# live	%228
# live	%228
# live	%228
# live	%228
# live	%228
# live	%228
# live	%228
# live	%228
# ld	%0, r7
# ld	12, r7
# st	r1, r2
# st	r1, 12
# add r1, r1, r1
# sub r1, r1, r1
# #and -->>
# and r1, r1, r1
# and r1, %42, r1
# and r1, 12, r1
# and	%42, r1, r1
# and	%42, %42, r1
# and	%42, 12, r1
# and 12, r1, r1
# and 12, %42, r1
# and 12, 12, r1
# #<<-- and
# #or -->>
# or r1, r1, r1
# or r1, %42, r1
# or r1, 12, r1
# or	%42, r1, r1
# or	%42, %42, r1
# or	%42, 12, r1
# or 12, r1, r1
# or 12, %42, r1
# or 12, 12, r1
# #<<-- or
# #xor -->>
# xor r1, r1, r1
# xor r1, %42, r1
# xor r1, 12, r1
# xor	%42, r1, r1
# xor	%42, %42, r1
# xor	%42, 12, r1
# xor 12, r1, r1
# xor 12, %42, r1
# xor 12, 12, r1
# #xor <<--
# zjmp	%42
# #-->> ldi
# ldi	r1, r1, r1
# ldi	r1, %42, r1
# ldi	%42, r1, r1
# ldi	%42, %42, r1
# ldi	12, r1, r1
# ldi	12, %42, r1
# #ldi <<--
# #sti -->>
# sti	r1, r1, r1
# sti	r1, r1, %42
# sti	r1, %42, r1
# sti	r1, %42, %42
# sti	r1, 12, r1
# sti	r1, 12, %42
# #sti <<--
# fork	%42
# #lld -->>
# lld	%42, r1
# lld	12, r1
# #lld <<--
# #lldi -->>
# lldi	r1, r1, r1
# lldi	r1, %42, r1
# lldi	%42, r1, r1
# lldi	%42, %42, r1
# lldi	12, r1, r1
# lldi	12, %42, r1
<<<<<<< HEAD
# lfork	%42
=======
# lfork	%42
# aff		r1
>>>>>>> ba698ff02b7b6d22ece74009284ffa61070e7cc8
