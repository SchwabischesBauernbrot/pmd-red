@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_743_grp, bank_026
	.equ	seq_743_pri, 127
	.equ	seq_743_rev, 0
	.equ	seq_743_mvl, 127
	.equ	seq_743_key, 0

	.section .rodata
	.global	seq_743
	.align	2

@*********************** Track 01 ***********************@

seq_743_0:
	.byte	KEYSH , seq_743_key+0
	.byte	TEMPO , 280/2
	.byte		VOICE , 8
	.byte		VOL   , 127*seq_743_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		N02   , Cs2 , v112
	.byte	W01
	.byte		VOL   , 80*seq_743_mvl/mxv
	.byte	W01
	.byte		        82*seq_743_mvl/mxv
	.byte		N03   , Cn2 , v120
	.byte	W01
	.byte		VOL   , 83*seq_743_mvl/mxv
	.byte	W01
	.byte		        85*seq_743_mvl/mxv
	.byte	W01
	.byte		        87*seq_743_mvl/mxv
	.byte		N05   , En3 
	.byte	W01
	.byte		VOL   , 89*seq_743_mvl/mxv
	.byte		N02   , As1 , v032
	.byte	W02
	.byte		VOL   , 92*seq_743_mvl/mxv
	.byte	W02
	.byte		VOICE , 7
	.byte		VOL   , 94*seq_743_mvl/mxv
	.byte		N03   , An3 , v120
	.byte	W01
	.byte		VOL   , 98*seq_743_mvl/mxv
	.byte	W01
	.byte		        103*seq_743_mvl/mxv
	.byte	W01
	.byte		        109*seq_743_mvl/mxv
	.byte		N02   , Gn3 , v092
	.byte	W01
	.byte		VOL   , 117*seq_743_mvl/mxv
	.byte	W01
	.byte		        124*seq_743_mvl/mxv
	.byte		N02   , Fn3 , v040
	.byte	W01
	.byte		VOL   , 123*seq_743_mvl/mxv
	.byte	W02
	.byte		        122*seq_743_mvl/mxv
	.byte		N02   , Dn3 , v032
	.byte	W01
	.byte		VOL   , 121*seq_743_mvl/mxv
	.byte	W01
	.byte		        120*seq_743_mvl/mxv
	.byte		N01   , Cn3 , v020
	.byte	W01
	.byte		VOL   , 119*seq_743_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N11   , Dn3 , v012
	.byte	W01
	.byte		VOL   , 117*seq_743_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOL   , 110*seq_743_mvl/mxv
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		VOL   , 109*seq_743_mvl/mxv
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		VOL   , 106*seq_743_mvl/mxv
	.byte		BEND  , c_v+9
	.byte	W01
	.byte		VOL   , 101*seq_743_mvl/mxv
	.byte		BEND  , c_v+13
	.byte	W01
	.byte		VOL   , 93*seq_743_mvl/mxv
	.byte	W01
	.byte		        84*seq_743_mvl/mxv
	.byte	W01
	.byte		        72*seq_743_mvl/mxv
	.byte	W01
	.byte		        58*seq_743_mvl/mxv
	.byte	W01
	.byte		        42*seq_743_mvl/mxv
	.byte	W01
	.byte		        23*seq_743_mvl/mxv
	.byte	W01
	.byte		        0*seq_743_mvl/mxv
	.byte	FINE

@******************************************************@

	.align	2

seq_743:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_743_pri	@ Priority
	.byte	seq_743_rev	@ Reverb

	.word	seq_743_grp

	.word	seq_743_0

	.end