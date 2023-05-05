// deposit money
// determine lines
// collect bet amount
// play the game
// check for wins
// return output and/or winning
// check if repeatable and ask for new gameplay

const prompt = require("prompt-sync")();

const rows = 3;
const cols = 3;

const symbols_count = {
    "$":2,
    "@":4,
    "%":6,
    "#":8
}

const symbols_values = {
    "$":5,
    "@":4,
    "%":3,
    "#":2
}

//deposit money
const getDeposit = () => {
    while (true){
        const stramount = prompt("Enter a deposit amount: $");
        const amount = parseFloat(stramount);

        if (isNaN(amount) || amount <= 0){
            console.log("Invalid deposit amount. Try again");
        }
        else{return amount;}
    }
}   

const getLines = () => {
    while (true){
        const strlines = prompt("Enter the number of lines to place a bet on (1-3): ");
        const lines = parseFloat(strlines);

        if (isNaN(lines) || lines <= 0 || lines > 3){
            console.log("Invalid number of lines. Try again");
        }
        else{return lines;}
    }
}   

const getBet = (balance,lines) => {
    while (true){
        const strbet = prompt("How much would you like to bet per line: ");
        const bet = parseFloat(strbet);

        if (isNaN(bet) || bet <= 0 || bet > balance/lines){
            console.log("Invalid bet amount. Try again");
        }
        else{return bet;}
    }
}

const spin = () => {
    const symbols = [];
    for(const [symbol, count] of Object.entries(symbols_count)){
        for (let i = 0; i < count; i++){
            symbols.push(symbol);
        }
    }
    const reels = [];
    for (let a = 0; a < cols; a++){
        reels.push([]);
        const reelSymbols = [...symbols];
        for (let b=0; b < rows; b++){
            const randIndex = Math.floor(Math.random() * reelSymbols.length);
            const selectedsymbol = reelSymbols[randIndex]
            reels[a].push(selectedsymbol);
            reelSymbols.splice(randIndex, 1);
        }
    }
    return reels;
};

const transpose = (reels) => {
    const row = [];
    
    for (let i = 0; i < rows; i++){
        row.push([]);
        for (let j = 0; j < cols; j++){
            row[i].push(reels[j][i])
        }
    }
    return row
}

const result = (transrows) => {
    console.log();
    console.log("Here is your play result ");
    for (const row of transrows){
        let rowString = '';
        for (const[i, symbol] of row.entries()){
            rowString += symbol
            if (i != row.length - 1){
                rowString += " | "
            }
        }
        console.log(rowString);
    }
    
}

const getWinnings = (transrows, bets, lines) => {
    let winnings = 0;

    for (let row = 0; row < lines; row++){
        const symbols = transrows[row];
        let similar = true;

        for (const symbol of symbols){
            if (symbol != symbols[0]){
                similar = false;
                break;
            }
        }

        if (similar){
            winnings += (bets * symbols_values[symbols[0]])
        }
    }
    return winnings;
}

const game = () => {
    let balance = getDeposit();

    while(true){
        
        const lines = getLines();
        const bets = getBet(balance, lines);
        balance -= bets * lines
        const reels = spin();
        const transrows = transpose(reels);
        //console.log(reels);
        //console.log(transrows);
        result(transrows);
        const winnings = getWinnings(transrows, bets, lines);
        balance += winnings;
        console.log();
        console.log("You won $" + winnings.toString() + " and spent $" + (bets * lines));
        console.log("You have a balance of $" + balance);

        if (balance <= 0){
            console.log("You ran out of money");
            break;
        }

        const playagain = prompt("Enter any key to continue or 'n' to stop: ");
        if (playagain == "n"){break;}

    }
}

game();