// Data for the "HTML Audio" Page

var audio = {
    controls: true,
    source: [
        {
            src:
                'https://scs.senecac.on.ca/~tanvir.alam/shared/fall-2018/web222/Track03.mp3',
            type: 'audio/mpeg'
        },
        {
            src:
                'https://scs.senecac.on.ca/~tanvir.alam/shared/fall-2018/web222/Track03.ogg',
            type: 'audio/ogg'
        }
    ]
};


window.onload = () => {
    var x = document.createElement('audio');
    document.getElementById('audio').appendChild(x);
   
    if (!audio.controls) {
        for (let i of audio.source) {
            x.src = i.src;
            x.type = i.type;
            x.controls = false;
        }
    }
    else if(audio.controls) {
        for (let i of audio.source) {
            x.src = i.src;
            x.type = i.type;
            x.controls = true;
        }
    }
      
    
};
