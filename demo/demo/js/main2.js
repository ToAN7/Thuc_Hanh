window.addEventListener("load", function() {
    let close = this.document.getElementsByClassName("close");
    let parent = this.document.querySelector(".products");
    for (let c of close) {
        c.onclick = function () {
            if (confirm("Ban co muon xoa san pham nay?") === true) {
                parent.removeChild(c.parentElement.parentElement);
            }
        }
    }
    
    let show = this.document.querySelector(".insert");
    let form = this.document.querySelector(".form");
    show.addEventListener("click", function() {
        form.classList.toggle("show");
    });

    let addBtn = this.document.querySelector(".btn");
    let defaultChild = this.document.querySelector("main>div.product");
    addBtn.addEventListener("click", function() {
        let name = form.children[0].value;
        let price = form.children[1].value;
        let addimg = form.children[2].value;
        parent.innerHTML=```
        <div class="product">
            <div>
                <span class = "close">&times;</span>
                <img src="${addimg}" alt="Phone" />
                <h2>${name}</h2>
                <div class="price">${price}<sup>đ</sup></div>
            </div>
        </div>
        ${parent.innerHTML}```;
    });
});