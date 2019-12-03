//@ts-check

const day1 = require('./day1');
const day2 = require('./day2');
const day3 = require('./day3');

const fs = require('fs');


const date = fs.readFileSync('./date.in', 'utf8');

day1.main(date);

