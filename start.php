<?php

include('db.con.php');
$sql = "SELECT `state` FROM `statu` WHERE 1";
$result = $con->query($sql);
if($result->num_rows > 0) {
    $row = $result->fetch_assoc();
    echo $row["state"];
}
else{
    echo "OFF";
}
$con->close();
?>