.ORIG x3000        ; Начальный адрес программы

; Основная программа
LEA R0, HW  ; Загружаем адрес строки в R0
PUTS ; Выводим строку в консоль

HALT ; Остановка процессора

; Данные программы
HW .STRINGZ "Hello World!" ; Строка с нулевым окончанием

.END ; Конец программы


