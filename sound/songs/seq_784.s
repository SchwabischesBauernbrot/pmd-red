@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_784_grp, bank_026
	.equ	seq_784_pri, 127
	.equ	seq_784_rev, 0
	.equ	seq_784_mvl, 127
	.equ	seq_784_key, 0

	.section .rodata
	.global	seq_784
	.align	2

@*********************** Track 01 ***********************@

seq_784_0:
	.byte	KEYSH , seq_784_key+0
	.byte	TEMPO , 150/2
	.byte		VOICE , 4
	.byte		VOL   , 127*seq_784_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 63*seq_784_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		BENDR , 24
	.byte		VOL   , 64*seq_784_mvl/mxv
	.byte	W01
	.byte		        66*seq_784_mvl/mxv
	.byte	W02
	.byte		        69*seq_784_mvl/mxv
	.byte		N01   , Fs3 , v120
	.byte	W01
	.byte		VOL   , 71*seq_784_mvl/mxv
	.byte	W01
	.byte		N01   , Gn3 
	.byte	W01
	.byte		VOL   , 74*seq_784_mvl/mxv
	.byte		N01   , Gs3 
	.byte	W01
	.byte		VOL   , 75*seq_784_mvl/mxv
	.byte	W01
	.byte		        77*seq_784_mvl/mxv
	.byte		N01   , An3 
	.byte	W01
	.byte		VOL   , 78*seq_784_mvl/mxv
	.byte		N01   , As3 
	.byte	W01
	.byte		VOL   , 79*seq_784_mvl/mxv
	.byte	W01
	.byte		        81*seq_784_mvl/mxv
	.byte		N01   , Bn3 
	.byte	W01
	.byte		VOL   , 82*seq_784_mvl/mxv
	.byte		N01   , Cn4 
	.byte	W01
	.byte		VOL   , 84*seq_784_mvl/mxv
	.byte	W01
	.byte		        87*seq_784_mvl/mxv
	.byte		N01   , Cs4 
	.byte	W01
	.byte		VOL   , 89*seq_784_mvl/mxv
	.byte		N01   , Dn4 
	.byte	W01
	.byte		VOL   , 90*seq_784_mvl/mxv
	.byte		N01   , Cs4 
	.byte	W01
	.byte		VOL   , 92*seq_784_mvl/mxv
	.byte	W01
	.byte		        93*seq_784_mvl/mxv
	.byte		N01   , Dn4 
	.byte	W01
	.byte		VOL   , 94*seq_784_mvl/mxv
	.byte		N01   , Ds4 , v080
	.byte	W01
	.byte		VOL   , 95*seq_784_mvl/mxv
	.byte	W01
	.byte		        97*seq_784_mvl/mxv
	.byte		N01   , Dn4 , v120
	.byte	W01
	.byte		VOL   , 98*seq_784_mvl/mxv
	.byte		N04   , En4 , v080
	.byte	W04
	.byte	FINE

@******************************************************@

	.align	2

seq_784:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_784_pri	@ Priority
	.byte	seq_784_rev	@ Reverb

	.word	seq_784_grp

	.word	seq_784_0

	.end