const fs = require('fs');

fs.readFile('./writeme.txt', (err,data) => {
    if (err) {
        throw err;
    }
    console.log(data);
    console.log(data.toString());
});
