// Rock Paper Scissors Game
// What it needs to do:
// Player needs to be able to choose an item
// When player choose item pictur of item shows in div
//computer pick doesn't show until after player has picked
//every round is scored
//

(function(){

// setting variables
let playerBoard = document.querySelector('#playerscore span');
let compBoard = document.querySelector('#compscore span');
let newPick;
let newItem;
let randomItem;
let compItem;
let compChoice = ['rock', 'paper', 'scissors'];;
let playerChoice;
const rock = document.querySelector('#rockbtn');
const paper = document.querySelector('#paperbtn');
const scissors = document.querySelector('#scissorsbtn');
const reset = document.querySelector('#newgame');
const playerImg = document.querySelector('.playeritem');
const compImg = document.querySelector('.compitem');
const scoreBoard = document.querySelector('#scoreboard');

pickItem();

function pickItem(){
	// make the computer choice random
	randomItem = Math.floor(Math.random()*3);
	// random index number of compchoice array
	compItem = compChoice[randomItem];
}


//where to look for items when button is clicked
function showRock(){
	playerImg.src = 'assets/images/rock.png';
	playerChoice = compChoice[0];
	// show compPick after player pick
	doThis();
}
function showPaper(){
	playerImg.src = 'assets/images/paper.png';
	playerChoice = compChoice[1];
	// show compPick after player pick
	doThis();
}
function showScissors(){
	playerImg.src = 'assets/images/scissors.png';
	playerChoice = compChoice[2];
	// show compPick after player pick
	doThis();
}

// show items when button clicked
rock.addEventListener('click', showRock);
paper.addEventListener('click', showPaper);
scissors.addEventListener('click', showScissors);
// resets game
reset.addEventListener('click', clearScreen);


// show compchoice image
function compPick(){
	if(compItem === 'rock'){
		compImg.src = 'assets/images/rock.png';
	}else if(compItem === 'paper'){
		compImg.src = 'assets/images/paper.png';
	}else{
		compImg.src = 'assets/images/scissors.png';
	}
}

// determine winner and add score
function winner(){
	if(playerChoice === 'rock' && compItem === 'scissors' || playerChoice === 'paper' && compItem === 'rock' || playerChoice === 'scissors' && compItem === 'paper'){
		console.log('You Win!!');
		playerBoard.textContent++;
		playerImg.classList.add('winner');
		compImg.classList.remove('winner');
	}else if(playerChoice === 'scissors' && compItem === 'rock' || playerChoice === 'rock' && compItem === 'paper' || playerChoice === 'paper' && compItem === 'scissors'){
		console.log('You Lose!!');
		compBoard.textContent++;
		compImg.classList.add('winner')
		playerImg.classList.remove('winner');
	}else{
		console.log('It\'s a Tie!!');
		playerImg.classList.remove('winner');
		compImg.classList.remove('winner');
	}
}
// clears images after each turn
function nextTurn(){
	compImg.src = '';
	playerImg.src = '';
}
// function that runs each time there's a new turn
function doThis(){
	compPick();
	winner();
	pickItem();
	setTimeout(nextTurn, 2000);
}
// function to reset game
function clearScreen(){
	compBoard.textContent = 0;
	playerBoard.textContent = 0;
	playerImg.src = '';
	compImg.src = '';
}

})();