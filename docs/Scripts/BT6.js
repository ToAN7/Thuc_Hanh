window.onload = function() {
    let main = document.getElementById("main");
    let images = document.querySelectorAll(".thumb img")
    for (let im of images) {
        im.onclick = function() {
            main.src = this.src;
        }
    }

    let colors = document.querySelectorAll(".buttons button")
    let footer = document.getElementById("footer")
    let pictures = document.querySelectorAll(".product > div")
    for (let clr of colors) {
        clr.onclick = function() {
            for (let pic of pictures) {
                pic.style.background = `linear-gradient(blue,${this.style.backgroundColor})`;
            }
            main.src = `images/Phone/galaxys8/${this.style.backgroundColor} (1).jpg`;
            for (let i = 0; i < images.length; i++) {
                images[i].src = `images/Phone/galaxys8/${this.style.backgroundColor} (${i+1}).jpg`;
            }
            footer.style.backgroundColor = this.style.backgroundColor;

        }
    }

    let name = document.getElementById("find"); 
    let temp;
    name.onchange = function() {
        if (temp == name.value) {
            console.log("ENTER");
        }
        console.log(name.value)
    }
}
