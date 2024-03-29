<?php 
    namespace views;
    require '../../../app/autoloader.php';
    include "../layouts/main.php";
    use Controllers\auth\LoginController as LoginController;
    $ua = new LoginController;
    is_null($ua->sessionValidate()) ? header('Location: /ProgramacionPPW/Ejercicio4profe/resources/views/auth/login.php') : '';
    head($ua);
?>

<section class="container pt-5"> 
    <h1 class="border-bottom">Mis publicaciones</h1>
  

    <div class="card">
        <div class="card-body">
           <table class="table table-striped">
            <thead>
                <th>Título</th>
                <th>Fecha</th>
                <th><i class="bi bi-gear"></i></th>
            </thead>
            <tbody id="my-posts">

            </tbody>
           </table>
        </div>        
        <div class="card-footer">
           
        </div>
    </div>

   
</section>

<?php
    scripts("app_myposts");
?>
<script>
    $(function(){
        app_myposts.getMyPosts(<?=$ua->id?>);
    });
</script>
<?php
    foot();