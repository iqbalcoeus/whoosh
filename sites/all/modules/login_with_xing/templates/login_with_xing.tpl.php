<?php
/**
 * @file
 * Login with xing button page.
 */
?>
<script id="lwx" src="https://www.xing-share.com/plugins/login.js"></script>
<script>
    var getUrl = window.location;
    var baseUrl = getUrl .protocol + "//" + getUrl.host + "/";

    onXingLogout();

    // This function is called by the plugin after login
    function onXingAuthLogin(response) {
        var urlPostfix='';

        if (response.user) {
            var userObj = response.user;

            const postParams = new URLSearchParams();

            Object.keys(userObj).forEach(key => postParams.append(key, userObj[key]));


            userData = postParams.toString() +"&img_url="+ userObj.photo_urls.maxi_thumb;
            console.log(baseUrl+'/login_with_xing/save?'+userData);

            urlPostfix ='?'+userData;

        } else if (response.error) {
            console.log(response.error);
        }
        window.location.href = baseUrl+'/login_with_xing/save'+urlPostfix;
    }

    function onXingLogout(){
        var response=xing.logout();
    }
</script>
<div class="xing_apply_btn">
    <b>
        <a href="#" class="hidden">
            <script type="xing/login">
            {
              "consumer_key": "<?php echo variable_get('login_with_xing_ckey') ?>",
              "color":"grey",
              "size":"large"
            }
            </script>
        </a>
    </b>
</div>
