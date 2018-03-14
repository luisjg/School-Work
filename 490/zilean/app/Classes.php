<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Classes extends Model
{
    protected $fillable = [
      'class_code',
        'name',
        'units'
    ];

    public function user_classes()
    {
        return $this->hasMany('App\User_classes');
    }
}
