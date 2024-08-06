window.onload = function() {
    /* add animation */
    let eles = document.querySelectorAll(".forum");
    for(let e of eles)
        e.classList.add("wow");
    
    let evenEles = document.querySelectorAll(".forum:nth-child(even)");
    for(let e of evenEles)
        e.classList.add("animate__backInLeft");

    let oddEles = document.querySelectorAll(".forum:nth-child(odd)");
    for(let e of oddEles)
        e.classList.add("animate__backInRight");

    /* init wow */
    wow = new WOW(
        {
        boxClass:     'wow',      // default
        animateClass: 'animate__animated', // default
        offset:       0,          // default
        mobile:       true,       // default
        live:         true        // default
      }
      )
        wow.init();
}