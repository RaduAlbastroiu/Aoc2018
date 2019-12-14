//@ts-check

const day1 = require('./day1');
const day2 = require('./day2');
const day3 = require('./day3');
const day4 = require('./day4');
const day5 = require('./day5');
const day6 = require('./day6');
const day7 = require('./day7');
const day8 = require('./day8');
const day9 = require('./day9');
const day12 = require('./day12');
const day14 = require('./day14');


const fs = require('fs');


const date = fs.readFileSync('./date.in', 'utf8');

day14.main(date);

