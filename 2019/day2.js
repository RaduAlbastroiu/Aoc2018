//@ts-check

function main(input)
{
  let vsafe = input.split(",");
  vsafe = vsafe.map(element => {
    return parseInt(element);
  });

  for(var ii = 1; ii <= 100; ii ++)
  {
    for(var jj = 1; jj <= 100; jj++)
    {
      let v = [...vsafe];
      v[1] = ii;
      v[2] = jj;
    
      for(var i = 0; true; i += 4) {
        if(v[i] == 1) {
          v[v[i + 3]] = v[v[i + 1]] + v[v[i + 2]];
        } 
        else {
          if(v[i] == 2) {
            v[v[i + 3]] = v[v[i + 1]] * v[v[i + 2]];
          }
          else
          {
            if(v[0] == 19690720)
            {
              console.log(ii*100 + jj);
              return;
            }
            break;
          }
        }
      }
    }
  }
  
}

module.exports = {main};