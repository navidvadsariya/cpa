// Data for the "HTML Video" Page

var video = {
    controls: true,
    width: 320,
    height: 240,
    source: [
        {
            src:
                'https://scs.senecac.on.ca/~tanvir.alam/shared/fall-2018/web222/movie.mp4',
            type: 'video/mp4'
        },
        {
            src:
                'https://scs.senecac.on.ca/~tanvir.alam/shared/fall-2018/web222/movie.ogg',
            type: 'video/ogg'
        }
    ]
};

window.onload = () => {
    var y = document.createElement('video');
    document.getElementById('video').appendChild(y);
    if (!video.controls) {
        y.width = video.width;
        y.height = video.height;
        y.controls = false ;
       
        for (let i of video.source) {
            y.src = i.src;
            y.type = i.type;
        }
    }
    else if(video.controls){
        y.width = video.width;
        y.height = video.height;
        y.controls = true;
       
        for (let i of video.source) {
            y.src = i.src;
            y.type = i.type;
        }
    }
    
};