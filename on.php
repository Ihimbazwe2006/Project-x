<?php
include('db.con.php');

$result = mysqli_query($con , "UPDATE `statu` SET `state`='ON' WHERE 1");
if($result){
    echo "ON";
}

?>