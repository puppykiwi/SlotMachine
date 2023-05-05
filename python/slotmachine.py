import random

MAX_LINES = 3
MAX_BET = 100
MIN_BET = 1

ROWS = 3
COLS = 3

symbol_count = {
    'A':2,
    'B':3,
    'C':4,
    'D':5
}

symbol_value = {
    'A':6,
    'B':4,
    'C':3,
    'D':2
}

def check_win(columns, lines, bet, values):
    winnings = 0
    winning_lines = []
    for line in range(lines):
        symbol = columns[0][line]
        for column in columns:
            symbol_to_check = column[line]
            if symbol != symbol_to_check:
                break
        else:
            winnings += values[symbol] * bet
            winning_lines.append(line + 1)

    return(winnings,winning_lines)


    

def get_slot_result(rows, cols, symbols):
    all_symbols = []
    for symbol, symbol_count in symbols.items():
        for _ in range (symbol_count):
            all_symbols.append(symbol)

    columns = []
    for _ in range (cols):
        column = []
        current_symbols = all_symbols[:]
        for _ in range (rows):
            value = random.choice(current_symbols)
            current_symbols.remove(value)
            column.append(value)
        
        columns.append(column)
    
    return columns


def print_results(columns):
    for row in range(len(columns[0])):
        for i, column in enumerate(columns):
            if i != len(columns) - 1:
                print(column[row], end=' | ')
            else:
                print(column[row])
            
        print()



def deposit():
    while True:
        amount = input("How much would you like to deposit: ")
        if amount.isdigit():
            amount = int(amount)
            if amount > 0:
                break
            else:
                print("Your deposit must be greater than 0 : ")
        else:
            print("Please enter a valid number: ")

    return(amount)

def get_lines():
    while True:
        lines = input("Please enter the number of lines you want to bet on (1 - "+ str(MAX_LINES) +"): ")
        if lines.isdigit():
            lines = int(lines)
            if 1 <= lines <= MAX_LINES:
                break
            else:
                print("Please enter the number of lines you want to bet on (1 - "+ str(MAX_LINES) +"): ")
        else:
            print("Please enter a valid number: ")
  
    return(lines)


def get_bet():
    while True:
        amount = input("What would you like to bet on each line: ")
        if amount.isdigit():
            amount = int(amount)
            if MIN_BET <= amount <= MAX_BET:
                break
            else:
                print("Your bet must be between {} and {} ".format(MIN_BET,MAX_BET))
        else:
            print("Please enter a valid number: ")

    return(amount)


def game(balance):
    lines = get_lines()
    bet = get_bet()
    total_bet = bet * lines

    if total_bet > balance:
        print("You do not have enough to bet that amount, your current balance is {} shillings".format(balance))
        get_bet()

    print("You are betting {} shillings on {} lines." '\n' "Your total bet is {} shillings.".format(bet,lines,total_bet))
    print()

    slots = get_slot_result(ROWS, COLS, symbol_count)
    print_results(slots)

    winnings, winning_lines = check_win(slots, lines, bet, symbol_value)
    print("You won {} shillings".format(winnings))

    return (winnings - total_bet)

def main():
    balance = deposit()
    while True:
        print("Current balance is {} shillings".format(balance))
        answer = input("Press Enter to play (q to quit)")
        if answer == 'q':
            break
        balance += game(balance)

    print("You are left with {} shillings".format(balance))

main()