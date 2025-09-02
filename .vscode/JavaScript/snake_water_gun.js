const prompt = require("prompt-sync")({ sigint: true });

const computer = () => { 
	console.log("Computer is playing its turn...");
	let comp_turn = Math.floor(Math.random() * 3) + 1;
    console.log("Computer selected " + ((comp_turn === 1) ? "Snake🐍" : ((comp_turn === 2) ? "Water💦" : "Gun🔫")));
	return (comp_turn === 1) ? "S" : ((comp_turn === 2) ? "W" : "G");
};

const human = () => {
	let hum_turn = prompt("Enter a character [S for 🐍: W for 💦: G for 🔫]::: ");
	hum_turn = hum_turn === "s" ? "S" : hum_turn === "w" ? "W" : hum_turn === "g" ? "G" : hum_turn;
	if (hum_turn != "S" && hum_turn != "W" && hum_turn != "G") {
		console.log("Not a valid input, please type correctly.!");
		return human();
	}
	return hum_turn;
};

const play = (rounds) => {
	const comp = 1,
		player = 0,
        snake = "S",
        water = "W",
        gun = "G";

	let score = [0, 0], winner = 0;

	console.log("Welcome to Snake 🐍 Water 💦 Gun 🔫");
	console.log("There will be " + rounds + " rounds of the Game. Be ready!");

	for (let i = 0; i < rounds; i++) {
		console.log("\nRound " + (i + 1));
		let hum_turn = human();
		let comp_turn = computer();

        if (hum_turn === comp_turn) {
            console.log("Oh! It's a Tie Round.! No point increment...");
        } else {
            if (hum_turn === snake) { winner = (comp_turn === gun) ? comp:player; }
            else if (hum_turn === water) { winner = (comp_turn === snake) ? comp:player; }
            else if (hum_turn === gun) { winner = (comp_turn === water) ? comp:player; }

            if (winner == player) {
                console.log("Congratulations, You won.!");
                score[player] += 1;
            }
            else {
                console.log("Bad Luck, Computer won.!");
                score[comp] += 1;
            }
        }
        console.log("Current Score:\nPlayer - " + score[player] + " Points\nComputer - " + score[comp] + " Points\n");
	}
    console.log("All rounds are ended...");
    if (score[player] > score[comp]) {
        console.log("Wow.! You won the Match...Congrats!!!");
    }
    else if (score[player] < score[comp]) {
        console.log("Oh No.! You lost the Match...Better Luck next time!!!");
    }
    else {
        console.log("Hey.! It was a Tie Match...Woderfull Play!!!");
    }
};

play(5);