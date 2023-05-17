const app_myposts = {

    url : "/ProgramacionPPW/Ejercicio4profe/app/app.php",

    mp : $("#my-posts"),
    dp : $("#deletePost"),
    vp : $("#verPost"),
    postsData : [],

    getMyPosts : function(uid){
        let html = `<tr><td colspan="3">Aún no tiene publicaciones</td></tr>`;
        this.mp.html("");
        fetch(this.url + "?_mp&uid=" + uid)
            .then( resp => resp.json())
            .then( mpresp => {
                if( mpresp.length > 0 ){
                    html = "";
                    for( let post of mpresp ){
                        html += `<tr>
                                    <td>${post.title}</td>
                                    <td>${post.created_at}</td>
                                    <td>
                                        <a href="#" class="link-primary" id="verPost" onclick=""><i class="bi bi-eye"></i></a>
                                        <a href="#" class="link-primary mx-2" onclick=""><i class="bi bi-pencil-square"></i></a>
                                        <a href="#" class="link-success" onclick=""><i class="bi bi-toggle-on"></i></a>
                                        <a href="#" class="link-secondary mx-2" id="deletePost" onclick=""><i class="bi bi-trash"></i></a>
                                    </td>
                                </tr>`;
                    }
                }
                this.mp.html(html);
            }).catch( err => console.error( err ));
            this.verPost(pid);  
    },

    
    
    
};
