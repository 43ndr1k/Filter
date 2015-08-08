	.file	"io.c"
	.comm	dateiname,8,8
	.comm	datei,8,8
	.globl	dateityp
	.data
	.type	dateityp, @object
	.size	dateityp, 5
dateityp:
	.string	".pnm"
	.comm	m_Breite,8,8
	.comm	m_Hoehe,8,8
	.comm	m_maxHelligkeit,8,8
	.comm	typVonPpm,8,8
	.comm	R,8,8
	.comm	G,8,8
	.comm	B,8,8
	.comm	Grau,8,8
	.globl	newHoehe
	.align 4
	.type	newHoehe, @object
	.size	newHoehe, 4
newHoehe:
	.long	-1
	.comm	neuerDateiName,8,8
	.section	.rodata
.LC0:
	.string	"r"
	.align 8
.LC1:
	.string	"Die folgende Datei wird eingelesen: %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	eingabeDateiname
	movq	%rax, dateiname(%rip)
.L4:
	movq	dateiname(%rip), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, datei(%rip)
	movq	datei(%rip), %rax
	testq	%rax, %rax
	jne	.L2
	call	menu1
	jmp	.L3
.L2:
	movq	datei(%rip), %rax
	movq	%rax, %rdi
	call	fclose
.L3:
	movq	datei(%rip), %rax
	testq	%rax, %rax
	je	.L4
	movq	dateiname(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	call	leseDatei
.L5:
	call	menu2
	jmp	.L5
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.string	"Bitte geben Sie den Dateinamen des Bildes an : "
	.text
	.globl	eingabeDateiname
	.type	eingabeDateiname, @function
eingabeDateiname:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	$30, %edi
	call	malloc
	movq	%rax, -24(%rbp)
	movl	$30, %edi
	call	malloc
	movq	%rax, neuerDateiName(%rip)
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movq	stdin(%rip), %rdx
	movq	-24(%rbp), %rax
	movl	$30, %esi
	movq	%rax, %rdi
	call	fgets
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	leaq	-1(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$10, %al
	jne	.L7
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	leaq	-1(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
.L7:
	movq	neuerDateiName(%rip), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	movq	neuerDateiName(%rip), %rbx
	movq	neuerDateiName(%rip), %rax
	movq	%rax, %rdi
	call	strlen
	subq	$4, %rax
	addq	%rbx, %rax
	movb	$0, (%rax)
	movq	-24(%rbp), %rax
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	eingabeDateiname, .-eingabeDateiname
	.section	.rodata
	.align 8
.LC3:
	.string	"\nEs ist bei dem \303\226ffnen der Datei ein Fehler aufgetreten! Bitte w\303\244hlen Sie!"
.LC4:
	.string	"1 : Dateiname \303\244ndern"
.LC5:
	.string	"2 : Programm beenden"
.LC6:
	.string	"Ihre Wahl: "
.LC7:
	.string	"%c"
	.align 8
.LC8:
	.string	"\nAktueller Dateiname lautet: %s\n"
.LC9:
	.string	"\nFalsche Eingabe!"
	.text
	.globl	menu1
	.type	menu1, @function
menu1:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$.LC3, %edi
	call	puts
.L12:
	movl	$.LC4, %edi
	call	puts
	movl	$.LC5, %edi
	call	puts
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	leaq	-1(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	nop
.L10:
	call	getchar
	cmpl	$10, %eax
	jne	.L10
	movzbl	-1(%rbp), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	toupper
	movb	%al, -1(%rbp)
	movzbl	-1(%rbp), %eax
	cmpb	$49, %al
	je	.L11
	movzbl	-1(%rbp), %eax
	cmpb	$50, %al
	jne	.L12
.L11:
	movzbl	-1(%rbp), %eax
	movsbl	%al, %eax
	cmpl	$49, %eax
	je	.L14
	cmpl	$50, %eax
	je	.L15
	jmp	.L17
.L14:
	movq	dateiname(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
	call	eingabeDateiname
	movq	%rax, dateiname(%rip)
	call	leseDatei
	jmp	.L9
.L15:
	movl	$0, %edi
	call	exit
.L17:
	movl	$.LC9, %edi
	call	puts
	nop
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	menu1, .-menu1
	.section	.rodata
.LC10:
	.string	"\nWas wollen Sie tun?!"
.LC11:
	.string	"1 : Graufilter"
.LC12:
	.string	"2 : \303\204ndere Farben"
.LC13:
	.string	"3 : Bild nur Speichern"
.LC14:
	.string	"4 : Programm beenden"
	.align 8
.LC15:
	.string	"Graufilter wird auf Datei Datei: %s angewendet\n"
	.align 8
.LC16:
	.string	"Farben werden geandert, auf die Datei Datei: %s angewendet\n"
.LC17:
	.string	"Bild wird gespeichert"
.LC18:
	.string	"Falsche Eingabe!"
	.text
	.globl	menu2
	.type	menu2, @function
menu2:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$.LC10, %edi
	call	puts
.L21:
	movl	$.LC11, %edi
	call	puts
	movl	$.LC12, %edi
	call	puts
	movl	$.LC13, %edi
	call	puts
	movl	$.LC14, %edi
	call	puts
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	leaq	-1(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	nop
.L19:
	call	getchar
	cmpl	$10, %eax
	jne	.L19
	movzbl	-1(%rbp), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	toupper
	movb	%al, -1(%rbp)
	movzbl	-1(%rbp), %eax
	cmpb	$49, %al
	je	.L20
	movzbl	-1(%rbp), %eax
	cmpb	$50, %al
	je	.L20
	movzbl	-1(%rbp), %eax
	cmpb	$51, %al
	je	.L20
	movzbl	-1(%rbp), %eax
	cmpb	$52, %al
	jne	.L21
.L20:
	movzbl	-1(%rbp), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$4, %eax
	ja	.L22
	movl	%eax, %eax
	movq	.L24(,%rax,8), %rax
	jmp	*%rax
	.section	.rodata
	.align 8
	.align 4
.L24:
	.quad	.L23
	.quad	.L25
	.quad	.L26
	.quad	.L27
	.quad	.L28
	.text
.L23:
	call	speicherfreigabe
	movq	dateiname(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
	call	eingabeDateiname
	movq	%rax, dateiname(%rip)
	call	leseDatei
	jmp	.L18
.L25:
	movq	dateiname(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC15, %edi
	movl	$0, %eax
	call	printf
	call	graufilter
	call	speichernGrau
	jmp	.L18
.L26:
	movq	dateiname(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC16, %edi
	movl	$0, %eax
	call	printf
	call	farbenAendern
	jmp	.L18
.L27:
	movl	$.LC17, %edi
	movl	$0, %eax
	call	printf
	call	speichernFarbe
	jmp	.L18
.L28:
	movl	$0, %edi
	call	exit
.L22:
	movl	$.LC18, %edi
	call	puts
	nop
.L18:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	menu2, .-menu2
	.section	.rodata
	.align 8
.LC19:
	.string	"Umg\303\274ltige Werte in der Datei %s!\n"
	.text
	.globl	temp
	.type	temp, @function
temp:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	call	leseZeichen
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L31
	movq	-8(%rbp), %rax
	jmp	.L32
.L31:
	movq	dateiname(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC19, %edi
	movl	$0, %eax
	call	printf
	call	menu1
	movl	$0, %eax
.L32:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	temp, .-temp
	.section	.rodata
.LC20:
	.string	"Kann %s nicht \303\266ffnen!"
	.text
	.globl	leseDatei
	.type	leseDatei, @function
leseDatei:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	dateiname(%rip), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, datei(%rip)
	movq	datei(%rip), %rax
	testq	%rax, %rax
	jne	.L34
	movq	dateiname(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC20, %edi
	movl	$0, %eax
	call	printf
.L34:
	movl	$0, -12(%rbp)
	jmp	.L35
.L43:
	call	leseZeichen
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L36
	movl	-12(%rbp), %eax
	cmpl	$1, %eax
	je	.L38
	cmpl	$1, %eax
	jg	.L39
	testl	%eax, %eax
	je	.L40
	jmp	.L37
.L39:
	cmpl	$2, %eax
	je	.L41
	cmpl	$3, %eax
	je	.L42
	jmp	.L37
.L40:
	movq	-8(%rbp), %rax
	movq	%rax, typVonPpm(%rip)
	jmp	.L37
.L38:
	movq	-8(%rbp), %rax
	movq	%rax, m_Breite(%rip)
	jmp	.L37
.L41:
	movq	-8(%rbp), %rax
	movq	%rax, m_Hoehe(%rip)
	jmp	.L37
.L42:
	movq	-8(%rbp), %rax
	movq	%rax, m_maxHelligkeit(%rip)
	nop
.L37:
	addl	$1, -12(%rbp)
	jmp	.L35
.L36:
	movq	dateiname(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC19, %edi
	movl	$0, %eax
	call	printf
	call	menu1
.L35:
	cmpl	$3, -12(%rbp)
	jle	.L43
	call	initialisiereMatrix
	call	matrixFuellen
	movq	datei(%rip), %rax
	movq	%rax, %rdi
	call	fclose
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	leseDatei, .-leseDatei
	.globl	leseZeichen
	.type	leseZeichen, @function
leseZeichen:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movb	$0, -21(%rbp)
	leaq	-21(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	addq	$1, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -16(%rbp)
	movq	$0, -8(%rbp)
	movq	-16(%rbp), %rax
	movl	$8, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	movl	$0, -20(%rbp)
	jmp	.L45
.L50:
	movq	datei(%rip), %rdx
	leaq	-21(%rbp), %rax
	movq	%rdx, %rcx
	movl	$1, %edx
	movl	$1, %esi
	movq	%rax, %rdi
	call	fread
	movzbl	-21(%rbp), %eax
	cmpb	$32, %al
	je	.L46
	movzbl	-21(%rbp), %eax
	cmpb	$10, %al
	je	.L46
	movzbl	-21(%rbp), %eax
	cmpb	$13, %al
	je	.L46
	movzbl	-21(%rbp), %eax
	cmpb	$9, %al
	jne	.L47
.L46:
	cmpl	$1, -20(%rbp)
	jne	.L48
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	addq	%rdx, %rax
	movb	$0, (%rax)
	movq	-16(%rbp), %rax
	jmp	.L52
.L48:
	jmp	.L45
.L47:
	movl	$1, -20(%rbp)
	leaq	-21(%rbp), %rcx
	movq	-16(%rbp), %rax
	movl	$1, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strncat
	leaq	-21(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	movq	-8(%rbp), %rdx
	addq	%rdx, %rax
	leaq	1(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc
	movq	%rax, -16(%rbp)
.L45:
	movq	datei(%rip), %rax
	movq	%rax, %rdi
	call	feof
	testl	%eax, %eax
	je	.L50
	cmpl	$1, -20(%rbp)
	jne	.L51
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	addq	%rdx, %rax
	movb	$0, (%rax)
	movq	-16(%rbp), %rax
	jmp	.L52
.L51:
	movl	$0, %eax
.L52:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	leseZeichen, .-leseZeichen
	.section	.rodata
.LC21:
	.string	"P2"
.LC22:
	.string	"P3"
	.align 8
.LC23:
	.string	"Das Dateiformat der Datei %s ist nicht korrekt!"
	.text
	.globl	initialisiereMatrix
	.type	initialisiereMatrix, @function
initialisiereMatrix:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	typVonPpm(%rip), %rax
	movl	$.LC21, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	je	.L54
	movq	typVonPpm(%rip), %rax
	movl	$.LC22, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L55
.L54:
	movq	m_Breite(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -8(%rbp)
	movq	m_Hoehe(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -4(%rbp)
	movq	R(%rip), %rax
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %ecx
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	matrixspeicher
	movq	%rax, R(%rip)
	movq	G(%rip), %rax
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %ecx
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	matrixspeicher
	movq	%rax, G(%rip)
	movq	B(%rip), %rax
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %ecx
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	matrixspeicher
	movq	%rax, B(%rip)
	movq	Grau(%rip), %rax
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %ecx
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	matrixspeicher
	movq	%rax, Grau(%rip)
	jmp	.L53
.L55:
	movq	dateiname(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC23, %edi
	movl	$0, %eax
	call	printf
	call	menu1
.L53:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	initialisiereMatrix, .-initialisiereMatrix
	.section	.rodata
	.align 8
.LC24:
	.string	"Kein virtueller RAM mehr vorhanden ... !"
	.align 8
.LC25:
	.string	"Kein Speicher mehr fuer Zeile %d\n"
	.text
	.globl	matrixspeicher
	.type	matrixspeicher, @function
matrixspeicher:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movl	%edx, -48(%rbp)
	movl	-44(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L58
	movl	$.LC24, %edi
	movl	$0, %eax
	call	printf
.L58:
	movl	$0, -28(%rbp)
	jmp	.L59
.L61:
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movl	-48(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, (%rbx)
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L60
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC25, %edi
	movl	$0, %eax
	call	printf
.L60:
	addl	$1, -28(%rbp)
.L59:
	movl	-28(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L61
	movq	-24(%rbp), %rax
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	matrixspeicher, .-matrixspeicher
	.globl	matrixFuellen
	.type	matrixFuellen, @function
matrixFuellen:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	m_Breite(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -24(%rbp)
	movq	m_Hoehe(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -20(%rbp)
	movl	$0, -32(%rbp)
	jmp	.L64
.L67:
	movl	$0, -28(%rbp)
	jmp	.L65
.L66:
	movq	R(%rip), %rax
	movl	-32(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-28(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	leaq	(%rax,%rdx), %rbx
	call	temp
	movq	%rax, %rdi
	call	atoi
	movl	%eax, (%rbx)
	movq	G(%rip), %rax
	movl	-32(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-28(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	leaq	(%rax,%rdx), %rbx
	call	temp
	movq	%rax, %rdi
	call	atoi
	movl	%eax, (%rbx)
	movq	B(%rip), %rax
	movl	-32(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-28(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	leaq	(%rax,%rdx), %rbx
	call	temp
	movq	%rax, %rdi
	call	atoi
	movl	%eax, (%rbx)
	addl	$1, -28(%rbp)
.L65:
	movl	-28(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jl	.L66
	addl	$1, -32(%rbp)
.L64:
	movl	-32(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L67
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	matrixFuellen, .-matrixFuellen
	.section	.rodata
	.align 8
.LC26:
	.string	"Umwandeln der Matrix in Grauwerte"
	.text
	.globl	graufilter
	.type	graufilter, @function
graufilter:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	m_Breite(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -12(%rbp)
	movq	m_Hoehe(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -8(%rbp)
	movl	$.LC26, %edi
	call	puts
	movl	$0, -20(%rbp)
	jmp	.L69
.L73:
	movl	$0, -16(%rbp)
	jmp	.L70
.L72:
	movl	$0, -4(%rbp)
	movq	R(%rip), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	cvtsi2sd	%eax, %xmm0
	movsd	.LC27(%rip), %xmm1
	mulsd	%xmm0, %xmm1
	movq	G(%rip), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	cvtsi2sd	%eax, %xmm0
	movsd	.LC28(%rip), %xmm2
	mulsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm1
	movq	B(%rip), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	cvtsi2sd	%eax, %xmm0
	movsd	.LC29(%rip), %xmm2
	mulsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	cvttsd2si	%xmm0, %eax
	movl	%eax, -4(%rbp)
	movl	newHoehe(%rip), %eax
	cmpl	-4(%rbp), %eax
	jge	.L71
	movl	-4(%rbp), %eax
	movl	%eax, newHoehe(%rip)
.L71:
	movq	Grau(%rip), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	movl	%eax, (%rdx)
	addl	$1, -16(%rbp)
.L70:
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jl	.L72
	addl	$1, -20(%rbp)
.L69:
	movl	-20(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jl	.L73
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	graufilter, .-graufilter
	.section	.rodata
.LC30:
	.string	"w"
	.align 8
.LC31:
	.string	"Datei konnte nicht geoeffnet werden."
.LC32:
	.string	"Matrix Speichern"
.LC33:
	.string	"%4i %4i %4i "
	.text
	.globl	farbenAendern
	.type	farbenAendern, @function
farbenAendern:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$256, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movabsq	$7009401412050513473, %rax
	movq	%rax, -224(%rbp)
	movabsq	$7885363342295261810, %rax
	movq	%rax, -216(%rbp)
	movq	$0, -208(%rbp)
	leaq	-200(%rbp), %rdx
	movl	$0, %eax
	movl	$9, %ecx
	movq	%rdx, %rdi
	rep stosq
	movq	%rdi, %rdx
	movl	%eax, (%rdx)
	addq	$4, %rdx
	movq	neuerDateiName(%rip), %rdx
	leaq	-112(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	leaq	-224(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcat
	leaq	-112(%rbp), %rax
	movl	$.LC30, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -232(%rbp)
	cmpq	$0, -232(%rbp)
	jne	.L75
	movl	$.LC31, %edi
	call	puts
	jmp	.L74
.L75:
	movq	m_Breite(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -240(%rbp)
	movq	m_Hoehe(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -236(%rbp)
	movl	$.LC32, %edi
	call	puts
	movq	-232(%rbp), %rax
	movq	%rax, %rcx
	movl	$2, %edx
	movl	$1, %esi
	movl	$.LC22, %edi
	call	fwrite
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc
	movq	m_Breite(%rip), %rax
	movq	-232(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fputs
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$32, %edi
	call	fputc
	movq	m_Hoehe(%rip), %rax
	movq	-232(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fputs
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc
	movq	m_maxHelligkeit(%rip), %rax
	movq	-232(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fputs
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc
	movl	$0, -248(%rbp)
	jmp	.L77
.L80:
	movl	$0, -244(%rbp)
	jmp	.L78
.L79:
	movq	B(%rip), %rax
	movl	-248(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-244(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %esi
	movq	R(%rip), %rax
	movl	-248(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-244(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movq	B(%rip), %rax
	movl	-248(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-244(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %edx
	movq	-232(%rbp), %rax
	movl	%esi, %r8d
	movl	$.LC33, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	addl	$1, -244(%rbp)
.L78:
	movl	-244(%rbp), %eax
	cmpl	-240(%rbp), %eax
	jl	.L79
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc
	addl	$1, -248(%rbp)
.L77:
	movl	-248(%rbp), %eax
	cmpl	-236(%rbp), %eax
	jl	.L80
	movq	-232(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
.L74:
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L81
	call	__stack_chk_fail
.L81:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	farbenAendern, .-farbenAendern
	.section	.rodata
.LC34:
	.string	"typ: %s\n"
.LC35:
	.string	"breite: %s\n"
.LC36:
	.string	"hoehe: %s\n"
.LC37:
	.string	"helligkeit: %s\n"
.LC38:
	.string	"Matrix"
.LC39:
	.string	"%d %d %d "
	.text
	.globl	ausgabe
	.type	ausgabe, @function
ausgabe:
.LFB14:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	typVonPpm(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC34, %edi
	movl	$0, %eax
	call	printf
	movq	m_Breite(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC35, %edi
	movl	$0, %eax
	call	printf
	movq	m_Hoehe(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC36, %edi
	movl	$0, %eax
	call	printf
	movq	m_maxHelligkeit(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC37, %edi
	movl	$0, %eax
	call	printf
	movq	m_Breite(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -8(%rbp)
	movq	m_Hoehe(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -4(%rbp)
	movl	$.LC38, %edi
	call	puts
	movl	$0, -16(%rbp)
	jmp	.L83
.L86:
	movl	$0, -12(%rbp)
	jmp	.L84
.L85:
	movq	B(%rip), %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movq	G(%rip), %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %edx
	movq	R(%rip), %rax
	movl	-16(%rbp), %esi
	movslq	%esi, %rsi
	salq	$3, %rsi
	addq	%rsi, %rax
	movq	(%rax), %rax
	movl	-12(%rbp), %esi
	movslq	%esi, %rsi
	salq	$2, %rsi
	addq	%rsi, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC39, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -12(%rbp)
.L84:
	movl	-12(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jl	.L85
	movl	$10, %edi
	call	putchar
	addl	$1, -16(%rbp)
.L83:
	movl	-16(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jl	.L86
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	ausgabe, .-ausgabe
	.globl	speichernFarbe
	.type	speichernFarbe, @function
speichernFarbe:
.LFB15:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$256, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movabsq	$8083517546880462670, %rax
	movq	%rax, -224(%rbp)
	movq	$28014, -216(%rbp)
	leaq	-208(%rbp), %rdx
	movl	$0, %eax
	movl	$10, %ecx
	movq	%rdx, %rdi
	rep stosq
	movq	%rdi, %rdx
	movl	%eax, (%rdx)
	addq	$4, %rdx
	movq	neuerDateiName(%rip), %rdx
	leaq	-112(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	leaq	-224(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcat
	leaq	-112(%rbp), %rax
	movl	$.LC30, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -232(%rbp)
	cmpq	$0, -232(%rbp)
	jne	.L88
	movl	$.LC31, %edi
	call	puts
	jmp	.L87
.L88:
	movq	m_Breite(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -240(%rbp)
	movq	m_Hoehe(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -236(%rbp)
	movl	$.LC32, %edi
	call	puts
	movq	-232(%rbp), %rax
	movq	%rax, %rcx
	movl	$2, %edx
	movl	$1, %esi
	movl	$.LC22, %edi
	call	fwrite
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc
	movq	m_Breite(%rip), %rax
	movq	-232(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fputs
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$32, %edi
	call	fputc
	movq	m_Hoehe(%rip), %rax
	movq	-232(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fputs
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc
	movq	m_maxHelligkeit(%rip), %rax
	movq	-232(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fputs
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc
	movl	$0, -248(%rbp)
	jmp	.L90
.L93:
	movl	$0, -244(%rbp)
	jmp	.L91
.L92:
	movq	B(%rip), %rax
	movl	-248(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-244(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %esi
	movq	G(%rip), %rax
	movl	-248(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-244(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movq	R(%rip), %rax
	movl	-248(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-244(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %edx
	movq	-232(%rbp), %rax
	movl	%esi, %r8d
	movl	$.LC33, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	addl	$1, -244(%rbp)
.L91:
	movl	-244(%rbp), %eax
	cmpl	-240(%rbp), %eax
	jl	.L92
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc
	addl	$1, -248(%rbp)
.L90:
	movl	-248(%rbp), %eax
	cmpl	-236(%rbp), %eax
	jl	.L93
	movq	-232(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
.L87:
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L94
	call	__stack_chk_fail
.L94:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	speichernFarbe, .-speichernFarbe
	.section	.rodata
.LC40:
	.string	"%i"
	.text
	.globl	speichernGrau
	.type	speichernGrau, @function
speichernGrau:
.LFB16:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$256, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movabsq	$7236274435435622983, %rax
	movq	%rax, -224(%rbp)
	movq	$1835954222, -216(%rbp)
	leaq	-208(%rbp), %rdx
	movl	$0, %eax
	movl	$10, %ecx
	movq	%rdx, %rdi
	rep stosq
	movq	%rdi, %rdx
	movl	%eax, (%rdx)
	addq	$4, %rdx
	movq	neuerDateiName(%rip), %rdx
	leaq	-112(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	leaq	-224(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcat
	leaq	-112(%rbp), %rax
	movl	$.LC30, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -232(%rbp)
	cmpq	$0, -232(%rbp)
	jne	.L96
	movl	$.LC31, %edi
	call	puts
	jmp	.L95
.L96:
	movq	m_Breite(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -240(%rbp)
	movq	m_Hoehe(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -236(%rbp)
	movl	$.LC32, %edi
	call	puts
	movq	-232(%rbp), %rax
	movq	%rax, %rcx
	movl	$2, %edx
	movl	$1, %esi
	movl	$.LC21, %edi
	call	fwrite
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc
	movq	m_Breite(%rip), %rax
	movq	-232(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fputs
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$32, %edi
	call	fputc
	movq	m_Hoehe(%rip), %rax
	movq	-232(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fputs
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc
	movl	newHoehe(%rip), %edx
	movq	-232(%rbp), %rax
	movl	$.LC40, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc
	movl	$0, -248(%rbp)
	jmp	.L98
.L101:
	movl	$0, -244(%rbp)
	jmp	.L99
.L100:
	movq	Grau(%rip), %rax
	movl	-248(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-244(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %edx
	movq	-232(%rbp), %rax
	movl	$.LC40, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$32, %edi
	call	fputc
	addl	$1, -244(%rbp)
.L99:
	movl	-244(%rbp), %eax
	cmpl	-240(%rbp), %eax
	jl	.L100
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc
	addl	$1, -248(%rbp)
.L98:
	movl	-248(%rbp), %eax
	cmpl	-236(%rbp), %eax
	jl	.L101
	movq	-232(%rbp), %rax
	movq	%rax, %rdi
	call	fflush
	movq	-232(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
.L95:
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L102
	call	__stack_chk_fail
.L102:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	speichernGrau, .-speichernGrau
	.globl	speicherfreigabe
	.type	speicherfreigabe, @function
speicherfreigabe:
.LFB17:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	m_Hoehe(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -8(%rbp)
	movq	m_Breite(%rip), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -4(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L104
.L105:
	movq	R(%rip), %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	free
	movq	G(%rip), %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	free
	movq	B(%rip), %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	free
	movq	Grau(%rip), %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	free
	addl	$1, -12(%rbp)
.L104:
	movl	-12(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jl	.L105
	movq	R(%rip), %rax
	movq	%rax, %rdi
	call	free
	movq	G(%rip), %rax
	movq	%rax, %rdi
	call	free
	movq	B(%rip), %rax
	movq	%rax, %rdi
	call	free
	movq	typVonPpm(%rip), %rax
	movq	%rax, %rdi
	call	free
	movq	m_Breite(%rip), %rax
	movq	%rax, %rdi
	call	free
	movq	m_Hoehe(%rip), %rax
	movq	%rax, %rdi
	call	free
	movq	m_maxHelligkeit(%rip), %rax
	movq	%rax, %rdi
	call	free
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	speicherfreigabe, .-speicherfreigabe
	.section	.rodata
	.align 8
.LC27:
	.long	3848290697
	.long	1070801616
	.align 8
.LC28:
	.long	962072674
	.long	1071827124
	.align 8
.LC29:
	.long	2680059593
	.long	1069362970
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
