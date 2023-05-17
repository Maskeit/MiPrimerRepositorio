<?php

    namespace Controllers;

    use Models\posts;
    use Models\user;
    use Models\comments;
    use Controllers\auth\LoginController as LoginController;

    class PostController {

        private $userId;
        private $title;
        private $body;

        public function __construct(){
            $ua = new LoginController();
            $ua->sessionValidate();
            $this->userId = $ua->id;
        }

        public function getPosts($limit="",$pid = ""){
            $posts = new posts();
            $result = $posts->select(['a.id','a.title','a.body','date_format(a.created_at,"%d/%m/%Y") as fecha','b.name'])
                            ->join('user b','a.userId=b.id')
                            ->where( $pid != "" ? [['a.id',$pid]] : [] )
                            ->orderBy([['a.created_at','DESC']])
                            ->limit($limit)
                            ->get();
            return $result;
        }
/** clase online metodo aun en trabajo, mientras se dejacomo estaba
 *         public function getPosts($limit="",$pid = ""){
            $posts = new posts();
            $resultP = $posts->select(['a.id','a.title','a.body','date_format(a.created_at,"%d/%m/%Y") as fecha','b.name'])
                            ->join('user b','a.userId=b.id')
                            ->where( $pid != "" ? [['a.id',$pid]] : [] )
                            ->orderBy([['a.created_at','DESC']])
                            ->limit($limit)
                            ->get();
            $comments = new comments();
            $resultC = $comments->select(['name'],['comment'])->where([['postId',json_decode($resultP)[0]->id]])->get();
            return [$resultP,$resultC];
        }
 */
        public function newPost($datos){
            $post = new posts();
            $post->valores = [$datos['uid'],$datos['title'],$datos['body']];
            $result =$post->create();
            return;
            die;
        }

        public function getMyPosts($uid){
            $posts = new posts();
            $result = $posts->where([['userId',$this->userId]])->get();
            return $result;               
        }

        public function deletePost($pid){
            //aqui va el proceso
        }
        public function saveComment($datos){
            $comment = new comments();
            $user = new user();
            $u = $user->select(['name','email'])->where((['id',$this->userId]))->get();
            $u = json_decode($u);
            $comment->valores = [$datos['pid'], $u[0]->name, $u[0]->email, $datos['comment']];
            print_r($comment->create());

        }
    }