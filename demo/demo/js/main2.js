function deleteProduct(product) {
    let parent = this.document.querySelector(".products");
    if (confirm("Ban co muon xoa san pham nay?") === true) {
        parent.removeChild(product);
    }
}
window.addEventListener("load", function() {

    let close = this.document.getElementsByClassName("close");
    let parent = this.document.querySelector(".products");
    for (let c of close) {
        c.onclick = function () {
            deleteProduct(this.parentElement.parentElement);
        }
    }
    
    let show = this.document.querySelector(".insert");
    let form = this.document.querySelector(".form");
    show.addEventListener("click", function() {
        form.classList.toggle("show");
    });

    let addBtn = this.document.querySelector(".btn");
    addBtn.addEventListener("click", function() {
        let name = form.children[0].value;
        let price = form.children[1].value;
        let addimg = form.children[2].value;
        let first = parent.querySelector(".product:first-child");
        let h = `
        <div class="product">
            <div class = "new">
                <span onclick = "deleteProduct(this.parentElement.parentElement)" class = "close">&times;</span>
                <img src="${addimg}" alt="Phone" />
                <h2>${name}</h2>
                <div class="price">${price}<sup>đ</sup></div>
            </div>
        </div>`;

        first.insertAdjacentHTML("beforebegin", h);

        let tmo = setTimeout(function() {
            let tmps = parent.querySelector(".new");
            tmps.classList.remove("new");
            clearTimeout();
        }, 1000);
    });
});