//@ts-check
let moons = [];
let initialState = [];

function read(input)
{
  let moon1 = input.split("\n")[0];
  let moon2 = input.split("\n")[1];
  let moon3 = input.split("\n")[2];
  let moon4 = input.split("\n")[3];
  
  moon1 = moon1.split(",").map(x => parseInt(x));
  moon1.push(0, 0, 0);

  moon2 = moon2.split(",").map(x => parseInt(x));
  moon2.push(0, 0, 0);

  moon3 = moon3.split(",").map(x => parseInt(x));
  moon3.push(0, 0, 0);

  moon4 = moon4.split(",").map(x => parseInt(x));
  moon4.push(0, 0, 0);

  moons = [moon1, moon2, moon3, moon4];
}

function read2(input)
{
  let moon1 = input.split("\n")[0];
  let moon2 = input.split("\n")[1];
  let moon3 = input.split("\n")[2];
  let moon4 = input.split("\n")[3];
  
  moon1 = moon1.split(",").map(x => parseInt(x));
  moon1.push(0, 0, 0);

  moon2 = moon2.split(",").map(x => parseInt(x));
  moon2.push(0, 0, 0);

  moon3 = moon3.split(",").map(x => parseInt(x));
  moon3.push(0, 0, 0);

  moon4 = moon4.split(",").map(x => parseInt(x));
  moon4.push(0, 0, 0);

  initialState = [moon1, moon2, moon3, moon4];
}

function computeGravity()
{
  for(let i = 0; i < 4; i++)
  {
    for(let j = 0; j < 4; j++)
    {
      if(i == j)
      {
        continue;
      }

      for(let k = 0; k < 3; k++)
      {
        if(moons[i][k] > moons[j][k])
        {
          moons[i][k + 3] -= 1;
        }
        if(moons[i][k] < moons[j][k])
        {
          moons[i][k + 3] += 1;
        }
      }
    }
  }
}

function modifyPosition()
{
  for(let i = 0; i < 4; i++)
  {
    moons[i][0] += moons[i][3];
    moons[i][1] += moons[i][4];
    moons[i][2] += moons[i][5];
  }
}

function computeScore()
{
  let sum = 0;
  for(let i = 0; i < 4; i++)
  {
    let pot = (Math.abs(moons[i][0]) + Math.abs(moons[i][1]) + Math.abs(moons[i][2]));
    
    let v1 = Math.abs(moons[i][3]);
    let v2 = Math.abs(moons[i][4]);
    let v3 = Math.abs(moons[i][5]);
    let kin = (v1 + v2 + v3);
    
    sum += pot * kin;
  }
  console.log(sum);
}

function equal(nr)
{
  for(let j = 0; j < 4; j++)
  {
    if(moons[j][nr] != initialState[j][nr])
    {
      return false;
    }
  }
  return true;
}

function main(input)
{
  read(input);
  read2(input);

  let periodX = [];
  let periodY = [];
  let periodZ = [];

  for(let i = 0; i < 1000000; i++)
  {
    computeGravity();
    modifyPosition();

    if(equal(0))
    {
      periodX.push(i + 1);
    }
    if(equal(1)) {
      periodY.push(i + 1);
    }
    if(equal(2)) {
      periodZ.push(i + 1);
    }
  }

  console.log(periodX[1], " " , periodY[1], " ", periodZ[1]);
}

module.exports = {main};