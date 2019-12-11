//@ts-check

let minV = 999999;
let m = Array(10001).fill(0).map(x => { return Array(10001).fill(0)});

function doOne(input, value)
{
  let startValue = 1 * value;

  let dir = input.split(",").map(ele => {
    return ele.slice(0,1);
  });
  let dist = input.split(",").map(ele => {
    return parseInt(ele.slice(1));
  });

  let pozX = 5000;
  let pozY = 5000;
  for(let i = 0; i < dir.length; i++)
  {
    let h = 0;
    let v = 0;
    if(dir[i] == 'L')
    {
      h = -1;
    }
    if(dir[i] == 'R')
    {
      h = +1;
    }
    if(dir[i] == 'U')
    {
      v = +1;
    }
    if(dir[i] == 'D')
    {
      v = -1;
    }

    for(let ii = 0; ii < dist[i]; ii++)
    {
      startValue += 1 * value;
      pozX += h;
      pozY += v;
      if(pozX > 10000 || pozX < 0 || pozY > 10000 || pozY < 0)
      {
        console.log(minV);
        return;
      }
      
      if(m[pozX][pozY] == 0)
      {
        m[pozX][pozY] = startValue;
      }
      else
      {
        if(m[pozX][pozY] > 0 && startValue < 0)
        {
          minV = Math.min(-1 * startValue + m[pozX][pozY], minV);
        }
      }
    }
  }
}

function main(input)
{
  doOne(input.split("\n")[0], 1);
  doOne(input.split("\n")[1], -1);

  console.log(minV);
}

module.exports = {main};