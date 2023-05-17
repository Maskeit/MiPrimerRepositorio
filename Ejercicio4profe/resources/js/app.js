const ruta = "/ProgramacionPPW/Ejercicio4profe";
const app = {

    routes : {
        inisession : ruta + "/resources/views/auth/login.php",
        endsession :ruta + "/app/app.php?_logout",
        login : ruta +"/app/app.php",
        register : ruta + "/resources/views/auth/register.php",
        doregister : ruta + "/app/app.php",
        prevposts : ruta +"/app/app.php?_pp",
        lastpost : ruta +"/app/app.php?_lp",
        openpost : ruta +"/app/app.php?_op",
        newpost : ruta +"/resources/views/autores/newpost.php",
        myposts : ruta +"/resources/views/autores/myposts.php",
        savecomment : ruta +"/app/app.php",
    },
    user : {
        sv : false,
        id : "",
        tipo : "",
    },
    pp : $("#prev-posts"),
    lp : $("#content"),

    view : function(route){
        location.replace(this.routes[route]);
    },
    previousPosts : function(){
        let html = `<b>Aún no hay publicaciones en este blog</b>`;
        this.pp.html("");
        fetch(this.routes.prevposts)
            .then( resp => resp.json())
            .then( ppresp => {
                if( ppresp.length > 0){
                    html = "";
                    let primera = true;
                    for( let post of ppresp ){
                        html += `
                            <a href="#" onclick="app.openPost(event,${ post.id },this)"
                                class="list-group-item list-group-item-action ${ primera ? `active`:``} pplg">
                                <div class="w-100 border-bottom">
                                    <h5 class="mb-1">${ post.title }</h5>
                                    <small class="text-${ primera ? `light` : `muted` }">
                                        <i class="bi bi-calendar-week"></i> 
                                        ${ post.fecha }
                                    </small>
                                </div>
                                <small>
                                    <i class="bi bi-person-circle"></i>
                                    <b>${ post.name }</b>
                                </small>
                            </a>
                        `;
                        primera = false;
                    }
                    this.pp.html(html);
                }
            }).catch( err => console.error( err ));

    },
    lastPost : function(limit){
        let html = "<h2>Aún no hay publicaciones</h2>";
        this.lp.html("");

        fetch(this.routes.lastpost + "&limit=" + limit)
            .then( response => response.json())
            .then( lpresp => {
                if( lpresp.length > 0 ){
                    html = this.postHTMLLoad(lpresp);
                }
                this.lp.html(html);
            }).catch( err => console.error( err ));
    },
    openPost : function(event,pid,element){
        event.preventDefault();
        $(".pplg").removeClass("active");
        element.classList.add("active");
        this.lp.html("");
        let html = "";
        fetch(this.routes.openpost + "&pid=" + pid)
            .then( response => response.json())
            .then( post => {
                console.log(post[0]);
                html = this.postHTMLLoad(post);
                this.lp.html(html);
            }).catch( err => console.error( "Error al abrir la pulicación : ",err ));
    },
    postHTMLLoad : function(post){
        return `
        <div class="w-100 border-bottom">
            <h5 class="mb-1">${ post[0].title }</h5>
            <small class="text-muted">
                <i class="bi bi-calendar-week"></i> ${ post[0].fecha } | 
                <i class="bi bi-person-circle"></i> ${ post[0].name }
            </small>
            <p class="bm-1 border-bottom fs-3" style="text-align:justify;">
                ${ post[0].body }
            </p>
            <i class="bi bi-hand-thumbs-up"></i><span id="likes">${ 0 }</span>
            <p class="float-end">
                <span id="comentarios"> <i class="bi bi-chat-right-dots"></i> ${ 0 } comentarios </span>
            </p>

            <div class="input-group mb-3">
                <input type="text" class="form-control" ${this.user.sv ? '' : ' disable readonly '}
                        placeholder="${this.user.sv ? 'Deja tu comentario.' : 'Registrate para comentar.'}" 
                        name="comment" id="comment"
                        aria-label="Recipient's username" 
                        aria-describedby="button-addon2">
                <button class="btn btn-outline-secondary" type="button" id="button-addon2" onclick="app.saveComment(${post[0].id})">
                    <i class="bi bi-send"></i>
                </button>
            </div>
          
        </div>
    `;
    },
    saveComment(pid, uid){
        const datos = new FormData();
        datos.append('pid',pid);
        datos.append('uid',uid);
        datos.append("comment",$("#comment").val());
        datos.append('_sc',"");
        fetch(this.routes.savecomment,{
            method:"POST",
            body: datos
        }).then( () => {
            $("#comment").val("");
        }).catch(err =>console.error( "Hay un error: ", err));
    }
}