INCLUDE Irvine32.inc

.data
rows = 6
cols = 7
board BYTE rows * cols DUP('.') ; empty cells marked with '.'

.code
main PROC
    call printBoard
    exit
main ENDP

printBoard PROC
    mov esi, OFFSET board     ; ESI points to start of array
    mov ecx, rows             ; Outer loop = row counter

outerLoop:
    push ecx                  ; Save row counter
    mov ecx, cols             ; Inner loop = col counter

innerLoop:
    mov al, [esi]             ; Load one character into AL

    ; ----- Set color based on symbol -----
    cmp al, 'X'
    jne checkO
    mov eax, 0Ch              ; red for X (Player 1)
    call SetTextColor
    jmp printChar

checkO:
    cmp al, 'O'
    jne defaultColor
    mov eax, 0Eh              ; yellow for O (Player 2)
    call SetTextColor
    jmp printChar

defaultColor:
    mov eax, 0Fh          ; white color
    call SetTextColor
    mov al, '.'           ; force empty cell marker
    jmp printChar

printChar:
    call WriteChar            ; print the symbol

    ; reset to white before printing space
    mov eax, 0Fh
    call SetTextColor
    mov al, ' '
    call WriteChar

    inc esi
    loop innerLoop            ; next column

    call Crlf                 ; newline after row
    pop ecx                   ; restore row counter
    loop outerLoop            ; next row

    ; reset to white at the end (important!)
    mov eax, 0Fh
    call SetTextColor

    ret
printBoard ENDP
END main